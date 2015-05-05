#ifndef CMN_DEFINES_H
#define CMN_DEFINES_H

#include "settings.h"

//(nothing / neuron / axon / dendrite) (0/1/2/3)
#define NOTHING    0
#define NEURON     1
#define AXON       2
#define	DENDRITE   3
#define GROWTHCONE 4

#define dynamicArrayRealloc(type, arrayName, numberOfElements)      \
	type *tmpArrayName;                                             \
	tmpArrayName = new type[numberOfElements];                      \
                                                                    \
	if (numberOfElements != 0) {                                    \
		for(int i = 0; i < numberOfElements; i++) {                 \
			tmpArrayName[i] = arrayName[i];                         \
		}                                                           \
        delete [] arrayName;                                        \
	}                                                               \
                                                                    \
	arrayName = new type[++numberOfElements];                       \
                                                                    \
	if (numberOfElements != 0) {                                    \
		for(int i = 0; i < numberOfElements - 1; i++) {             \
			arrayName[i] = tmpArrayName[i];                         \
		}                                                           \
	}                                                               \
                                                                    \
	delete [] tmpArrayName

#define XYCORRECTIONCHECKER(x, y) ( ( (x >= 0) && (y >= 0) && x < NUMBEROFCELLSX && y < NUMBEROFCELLSY ) ? 1 : 0 )

#include <stdio.h>
#include <cstring> // For strlen

#ifdef TRACESON
#ifdef TRACEINFILE
//TODO:create trace groups
//TODO:it`s better to delete log file before program start in program somehow
#define TRACE(file, format, ...)            \
		fopen_s(&log, LOGFILENAME, "a");    \
		fprintf(log, file);                 \
		fprintf(log, ".cpp: ");             \
		fprintf(log, format, __VA_ARGS__);  \
		fprintf(log, "\n");                 \
		fclose(log);
#else
#define TRACE(file, format, ...)      \
		printf(file);                 \
		printf(".cpp: ");             \
		printf(format, __VA_ARGS__);  \
		printf("\n");
#endif

#else
#define TRACE(file, format, ...)
#endif

#if defined(TRACESON) || defined(STATISTICSON)
#define ENTER_FUNCTION(file, function, format, ...)      \
		FILE *log;                                       \
	    TRACE(file, "Entering function %s", function);   \
		if(strlen(format) != 0) { \
			TRACE(file, format, __VA_ARGS__); \
		}
#endif

#ifdef STATISTICSON
#define STATISTICS(file, format, ...)       \
		fopen_s(&log, file, "a");           \
		fprintf(log, format, __VA_ARGS__);  \
		fprintf(log, "\n");                 \
		fclose(log);

#ifdef LENGTHSTATISTICS
#define LENGTHSTATISTIC(format, ...)  STATISTICS(LENGTHSTATISTICSFILE, format, __VA_ARGS__)
#endif

#ifdef CONNECTIVITYGRAPHSTATISTICS
#define CONNECTIVITYGRAPHSTATISTIC(format, ...)  STATISTICS(CONNECTIVITYGRAPHSTATISTICSFILE, format, __VA_ARGS__)
#endif
#endif

#endif