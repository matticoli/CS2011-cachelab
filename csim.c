#include <stdio.h>
#include "cachelab.h"
#include "stdio.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
	int setIndex;
	CacheLine* lines;
} CacheSet;

//struct representing the whole cache
typedef struct cache {
	CacheSet* set;
} Cache;


void printUsage() {
	printf("./csim-ref: Missing required command line argument\n"
				   "Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
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
				   "  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n"
				   "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
	exit(1);
}

int getSetIndex(long tag, int s, int b){
	tag = tag >> b; //get rid of block bits
	tag = tag << (64 - s - b -b); //tag bits
	tag = tag >> (64 - s); //set index
	return tag;
}

/**
 * findLine: called on the cache to see if memory holds given address
 */

cacheLine findLine(int index, long tag, char instruction){
	for (int i = 0; i < numSets; i++) {
			for (int j = 0; j < numLines; j++) {
				if(this->tag == tag){
					return this;
				}
			}
		}
}

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


	//WE'RE SUPPOSED TO USE GETOPT HERE
	//man 3 getopt


	int verbose = 0;
	int s, e, b;// s e and b params
	char *t; // file name

	if(argc >= 9) { // Verbose flag and all other flags specified

		if(argc >= 10 && strcmp(argv[1],"-v") >= 0 && strcmp(argv[2],"-s") >= 0 && strcmp(argv[4],"-E") >= 0 &&
		     			 strcmp(argv[6],"-b") >= 0 && strcmp(argv[8],"-t") >= 0) {
			// Verbose and all args specified
			verbose = 1;

			// Get data from args
			s = (int)atoi(argv[3]); //number of set index bytes
			e = (int)atoi(argv[5]); //associativity
			b = (int)atoi(argv[7]); //number of block bytes
			t = argv[9];

		} else if(strcmp(argv[1],"-s") >= 0 && strcmp(argv[3],"-E") >= 0
				   && strcmp(argv[5],"-b") >= 0 && strcmp(argv[7],"-t") >= 0) {
			// Not verbose and all strings specified
			// Get data from args
			s = (int)atoi(argv[2]); //number of set index bytes
			e = (int)atoi(argv[4]); //associativity
			b = (int)atoi(argv[6]); //number of block bytes
			t = argv[8];
		} else {
			// Not all flags specified
			printUsage();
		}

	} else {
		printUsage();
	}

	if(!s || !e || !b) {
		printUsage();
	}

	/** PARSE INPUT **/



	/** MAKE CACHE BASED ON SPECS (probably could/should be a separate function)**/

	//allocate memory for cache
	malloc(s * e * b);

	//find cache dimensions
	int numSets = 2 << s;
	int numLines = 2 << e;
	int blockSize = 2 << b;

	// initialize cache with input dimensions
	for (int i = 0; i < numSets; i++) {
		for (int j = 0; j < numLines; j++) {
			CacheLine *line = malloc(sizeof(CacheLine));
			line->isValid = 0; //before anything is stored, all invalid
			line->tag = 0; // Tag starts blank
			line->offset = 0;
		}
	}

	//TODO: Get rid of this once blocksize in use
	if(verbose) {
		printf("%s, %d", t, blockSize);
	}

	// Open specified trace in read mode
	FILE *valgrind = fopen(t, "r");
	// If open failed, error and exit TODO

	do {
		char *s = malloc(sizeof(char) * 20); // valgrind line
		fgets(s, 20, valgrind);
		if(s) { // If not nullptr

			// Get instruction
			char instruction = s[0] == ' ' ? s[1] : s[0];

			// Get tag and numBytes
			char *tagString = malloc(sizeof(char) * 10); // Assume 10 max length of string (16^10 possible addresses)
			char *numBytesString = malloc(sizeof(char) * 2);
			sscanf(s+3, "%s,%s", tagString, numBytesString);
			long tag = (long)strtol(tagString, NULL, 16);
			int numBytes = (int)atoi(numBytesString);

			//THE SET INDEX (still confused)



			if(verbose) {
				printf("Instr: %c\t Addr %s\t%ld\t NumBytes %d\n", instruction, tagString, tag, numBytes);
//				printf("Instr %c\t", instruction);
//				printf("Addr %s\t", tagString);
//				printf("%ld\t", tag);
			}

//			free(tagString);
//			free(numBytesString);
//			free(s);

		}

	} while(s != EOF);// check for EOF TODO FIX



	/**HITS, MISSES, AND EVICTIONS **/

//TODO: find a way to search cache for memory addresses

	//L and S are treated the same way, M is essentially that logic but doubled
	switch (instruction) {
	case 'I':
		//this is an instruction load (ignore, it's just where we start)
		cache.findLine();

	case 'L':
		//this is a data load; (I'm guessing a read?)
		//at most one cache miss
		if(cache->isValid == 1 && strcmp(cacheLine->tag, tag) == 0){
			//if the valid bit of the line of the given address is set and the tag matches
			hit_count++;
		}
		if else{
			//nothing is in this location, the bit is not valid or the tag does not match, cache miss
			miss_count++;

		}

	case 'S':
		//this is a data store (I'm guessing a write?)
		//at most one cache miss
		if(cache->isValid == 1 && strcmp(cacheLine->tag, tag) == 0){
			//if there is data there and the address is valid, data is replaced
			hit_count++;

			eviction_count++;
			cacheLine->tag = tag;
		}
		if else(cache->isValid == 0 &&){
			//if there is no data at the memory address and the address is valid but data does not match
			miss_count++;
		}

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







