#include <stdio.h>
#include "cachelab.h"
#include "stdio.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
// Ann Jicha ahjicha
// Mikel Matticoli mamatticoli

#define DEBUG 0

// struct representing a line in cache memory
typedef struct cacheLine {
    unsigned long tag;
    int isValid; //1 if valid, 0 if not
    int offset;
    time_t access;
} CacheLine;

// struct representing a set of cache line(s)
typedef struct cacheSet {
    CacheLine **lines;
} CacheSet;

// struct representing the whole cache
typedef struct cache {
    CacheSet **sets;
} Cache;


// Global var for cache (just makes things easier)
Cache *cache;

// counters for hits, misses, and evictions
int hit_count = 0;
int miss_count = 0;
int eviction_count = 0;

/*
 * Prints out usage text for invalid input or help
 */
void printUsage();

/*
 * Gets tag that corresponds to a given mem loc
 * @param loc location to get tag for
 * @param lineLength block size (length of line)
 */
long getTagFromLoc(long loc, int lineLength);

/*
 * Get the set index for a given tag
 * @param tag to get set index for
 * @param s number if set index bits
 * @param b number of block offset bits
 */
int getSetIndex(long tag, int s, int b);

/*
 * Returns cache line in given set with matching tag, or null if cache miss
 *
 * @param setIndex set index
 * @param tag tag to search for
 * @param linesPerSet number of lines in a cache set
 * @param blockSize size of mem block held in each cache line
 */
CacheLine *getLine(int setIndex, long tag, int linesPerSet);

/*
 * Processes load/store for a cache line
 * @params line pointer to cache line to process save/load for
 * @param setIndex set index
 * @param tag tag
 * @param omitNewline 1 if omit newline in print statement else 0
 * @param numLines cache block size thing
 *
 */
void processInstruction(CacheLine *line, int setIndex, long tag, int numLines);


int main(int argc, char **argv) {
//
//
//
//    printf("please enter s e b valgrind");
//    /**		where the arguments are:
//     -h: Optional help flag that prints usage info
//     -v: Optional verbose flag that displays trace info
//     -s <s>: Number of set index bits (the number of sets is 2s)
//     -E <E>: Associativity (number of lines per set)
//     -b <b>: Number of block bits (the block size is 2b)
//     -t <tracefile>: Name of the valgrind trace to replay **/
//
//    /** CHECK FOR CORRECT INPUT **/


    // TODO geopt for arg parsing?
    // man 3 getopt


    int verbose = 0;
    int s, e, b;// s e and b params
    char *t; // file name

    if (argc >= 9) { // Verbose flag and all other flags specified

        if (argc >= 10 && strcmp(argv[1], "-v") >= 0 && strcmp(argv[2], "-s") >= 0 && strcmp(argv[4], "-E") >= 0 &&
            strcmp(argv[6], "-b") >= 0 && strcmp(argv[8], "-t") >= 0) {
            // Verbose and all args specified
            verbose = 1;

            // Get data from args
            s = (int) atoi(argv[3]); // number of set index bytes
            e = (int) atoi(argv[5]); // associativity
            b = (int) atoi(argv[7]); // number of block bytes
            t = argv[9];

        } else if (strcmp(argv[1], "-s") >= 0 && strcmp(argv[3], "-E") >= 0
                   && strcmp(argv[5], "-b") >= 0 && strcmp(argv[7], "-t") >= 0) {
            // Not verbose and all strings specified
            // Get data from args
            s = (int) atoi(argv[2]); // number of set index bytes
            e = (int) atoi(argv[4]); // associativity
            b = (int) atoi(argv[6]); // number of block bytes
            t = argv[8];
        } else {
            // Not all flags specified
            printUsage();
        }

    } else {
        printUsage();
    }

    if (!s || !e || !b) {
        printUsage();
    }

    /** PARSE INPUT **/



    /** MAKE CACHE BASED ON SPECS (probably could/should be a separate function)**/

    // allocate memory for cache

    // find cache dimensions
    int numSets = 2 << s;
    int numLines = 2 << e;
    int blockSize = 2 << b;


    // initialize cache with input dimensions
    cache = malloc(sizeof(Cache));
    cache->sets = (CacheSet **) malloc(sizeof(CacheSet *) * numSets);
    for (int i = 0; i < numSets; i++) {
        CacheSet *set = malloc(sizeof(CacheSet));
        cache->sets[i] = set;//TODO Fix this shit when it inevitably segfaults
        set->lines = malloc(sizeof(CacheLine *) * numLines);
        for (int j = 0; j < numLines; j++) {
            CacheLine *line = malloc(sizeof(CacheLine));
            set->lines[j] = line;
            line->isValid = 0; // before anything is stored, all invalid
            line->tag = 0; // Tag starts blank (This technically isn't necessary but whatever)
            line->offset = 0; // Don't even know what this is for yet
        }
    }

    // Open specified trace in read mode
    FILE *valgrind = fopen(t, "r");
    // If open failed, error and exit

    // TODO: find a way to search cache for memory addresses

    if (!cache) {
        // Failed to allocate cache
        printf("Failed to allocate memory for cache");
        exit(1);
    }

    char *str;

    do {
        str = malloc(sizeof(char) * 20); // valgrind line
        fgets(str, 20, valgrind);
        if (str) { // If not nullptr
            if(DEBUG) printf("Valgrind line:\t%s\n", str);
            // Get instruction
            char instruction = str[0] == ' ' ? str[1] : str[0];

            // Get tag and numBytes
            char *locString = malloc(sizeof(char) * 16); // Assume 10 max length of string (16^10 possible addresses)
            int *numBytesPtr = malloc(sizeof(int));
            sscanf(str + 3, "%s,%d", locString, numBytesPtr);
            long loc = (long) strtol(locString, NULL, 16);
            int numBytes = atoi(str + strlen(locString) + 2);//(int) atoi(numBytes);

            if(DEBUG) printf("Instruction parsed\n");

            if (verbose && (loc || numBytes)) {
            	printf("%s ", (str[0] == ' ' ? str + 1 : str));
            }

            // Now process the instruction

            /** HITS, MISSES, AND EVICTIONS **/
            // L and S are treated the same way, M is essentially that logic but doubled

            // Find cache line
            long tag = getTagFromLoc(loc, blockSize);
            int setIndex = getSetIndex(tag, s, b);
            CacheLine *line = getLine(setIndex, tag, numLines);

            switch (instruction) {
                case 'M':
                    // Load followed by save (processInstruction gets called twice)
                    processInstruction(line, setIndex, tag, numLines);
                    line = getLine(setIndex, tag, numLines);
                    /* no break */
                case 'L': // Data Load
                case 'S': // Data Store
                    // These are both handled the same for the purposes of this simulation
                    processInstruction(line, setIndex, tag, numLines);
                    printf("\n");
                    break;
                case 'I':
                    // This is an instruction load (ignore, it's just where we start)
                default:
                    // Unhandled instruction
                    break;
            }

        }

    } while (strlen(str) > 0);

    printf("\n");


    printSummary(hit_count, miss_count, eviction_count);
    return 0;
}

void printUsage() {
    printf("./csim-ref: Missing required command line argument\n"
                   "Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n"
                   "Arguments must be in order!\n\n"
                   "Options:\n"
                   "  -h         Print this help message.\n"
                   "  -v         Optional verbose flag.\n"
                   "  -s <num>   Number of set index bits.\n"
                   "  -E <num>   Number of lines per set.\n"
                   "  -b <num>   Number of block offset bits.\n"
                   "  -t <file>  Trace file.\n"
                   "\n"
                   "Examples:\n"
                   "  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n"
                   "  linux>  ./csim -v -s 8 -E ` -b 4 -t traces/yi.trace\n");
    exit(1);
}

long getTagFromLoc(long loc, int lineLength) {
    long tag = loc - (loc % lineLength);// (tag is loc % lineSize);
    if(DEBUG) printf("\nConverted loc %ld to tag %ld (line %d)\n", loc, tag, lineLength);
    return tag;
}

int getSetIndex(long tag, int s, int b) {
    tag = tag >> b; // Get rid of block bits
    tag = tag << (64 - s - b - b); // Tag bits
    tag = tag >> (64 - s); // Set index
    return tag;
}

CacheLine *getLine(int setIndex, long tag, int linesPerSet) {
    if(DEBUG) printf("getLine(%d, %ld, %d);\n", setIndex, tag, linesPerSet);
    CacheSet *set = cache->sets[setIndex];
// Index of line is tag / block size
    for (int j = 0; j < linesPerSet; j++) {
        if (set->lines[j]->tag == tag && set->lines[j]->isValid) {
            return set->lines[j];
        }
    }
    return NULL;
}

CacheLine *getEmptyLine(int setIndex, int numLines) {
	CacheSet *set = cache->sets[setIndex];
	CacheLine *line;
	time_t leastRecent = time(NULL);
	for(int i = 0; i < numLines; i++) {
		CacheLine *currentLine = set->lines[i];
		if(!(currentLine->isValid)) {
			return currentLine;
		} else {
			// valid block, check time
			if(currentLine->access < leastRecent) {
				leastRecent = currentLine->access;
				line = currentLine;
			}
		}
	}
	printf("eviction ");
	eviction_count++;
//	line->isValid = 0;
	return line;
}


void processInstruction(CacheLine *line, int setIndex, long tag, int numLines) {

    // At most one cache miss
    if(!line) {
        // Cache Miss, increment counter and cache it
        miss_count++;
        printf("miss ");
        CacheLine *line = getEmptyLine(setIndex, numLines);
        if(!line || line->isValid) {
        	printf("Something broke\n");
        	exit(1);
        } else {
        	line->tag = tag;
        	line->isValid = 1;
        }
    } else {
        // Cache Hit, increment counter and continue
        hit_count++;
        printf("hit ");
        line->access = time(NULL);
    }
}




