#include <stdio.h>
#include "cachelab.h"
#include "stdio.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
//Ann Jicha ahjicha
//Mikel Matticoli mmatticoli

//struct representing a line in cache memory
typedef struct cacheLine {
	unsigned long tag;
	int isValid; //1 if valid, 0 if not
	int offset;
} CacheLine;

//struct representing a set of cache line(s)
typedef struct cacheSet {
	CacheLine* lines;
} CacheSet;

//struct representing the whole cache
typedef struct cache {
	CacheSet* set;
} Cache;

int main(int argc, char** argv) {
	//counters for hits, misses, and evictions
	int hit_count = 0;
	int miss_count = 0;
	int eviction_count = 0;

	printf("please enter s e b valgrind");
	/**		where the arguments are:
	 -h: Optional help flag that prints usage info
	 -v: Optional verbose flag that displays trace info
	 -s <s>: Number of set index bits (the number of sets is 2s)
	 -E <E>: Associativity (number of lines per set)
	 -b <b>: Number of block bits (the block size is 2b)
	 -t <tracefile>: Name of the valgrind trace to replay **/

	/** CHECK FOR CORRECT INPUT **/

// TODO Args with flags
//    if(argv <= 8) {
//        printf("./csim-ref: Missing required command line argument\n"
//                       "Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
//                       "Options:\n"
//                       "  -h         Print this help message.\n"
//                       "  -v         Optional verbose flag.\n"
//                       "  -s <num>   Number of set index bits.\n"
//                       "  -E <num>   Number of lines per set.\n"
//                       "  -b <num>   Number of block offset bits.\n"
//                       "  -t <file>  Trace file.\n"
//                       "\n"
//                       "Examples:\n"
//                       "  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n"
//                       "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
//        return 1;
//    }


	//WE'RE SUPPOSED TO USE GETOPT HERE
	//man 3 getopt
	if (argc < 4) {
		printf("You have entered the wrong inputs, please try again");
		return 1;
	}

	/** PARSE INPUT **/

	int s = *argv[1]; //number of set index bytes
	int e = *argv[2]; //associativity
	int b = *argv[3]; //number of block bytes

	/** MAKE CACHE BASED ON SPECS (probably could/should be a separate function)**/

	//allocate memory for cache
	malloc(s * e * b);

	//find cache dimensions
	int numSets = 2 << s;
	int numLines = 2 << e;
	int blockSize = 2 << b;

	// initialize cache
	for (int i = 0; i < numSets; i++) {
		for (int j = 0; j < numLines; j++) {
			CacheLine line;
			line.tag = j; // I think? I'm not sure
			line.isValid = 0; //before anything is stored, all invalid
		}
	}

	//cache CacheUsed[numLines][numSets];
	//CacheUsed.cacheset = something; //gotta put somethin in

	/** DEAL WITH VALGRIND **/
	char whatDo;
	char* tag;
	int size;

	//the file needs to be opened somehow
	FILE *valgrind, *cacheInstruct;
	cacheInstruct = fopen(valgrind, r);

	int fscanf(FILE *valgrind, char *fomat," %c %s, %d", &whatDo, &tag, &size);
	fclose(valgrind);

	/**HITS, MISSES, AND EVICTIONS **/

	char whatDo; //somehow get this from input

	switch (whatDo) {
	case 'I':
		//this is an instruction load
	case 'L':
		//this is a data load;
		//at most one cache miss
	case 'S':
		//this is a data store
		//at most one cache miss
	case 'M':
		//this is a data load followed by a data store
		//two cache hits or a hit and a miss followed by a possible eviction
	default:
		break;
	}

	/** RETURN **/
	printSummary(hit_count, miss_count, eviction_count);
	return 0;
}
