/*
 *
 * honggfuzz - file operations
 * -----------------------------------------
 *
 * Author: Robert Swiecki <swiecki@google.com>
 *
 * Copyright 2010-2015 by Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License.
 *
 */

#ifndef _HF_FILES_H_
#define _HF_FILES_H_

#include "common.h"

#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

extern bool files_init(honggfuzz_t * hfuzz);

extern bool files_getNext(honggfuzz_t * hfuzz, char *fname, bool rewind);

extern ssize_t files_readFileToBufMax(char *fileName, uint8_t * buf, size_t fileMaxSz);

extern bool files_writeBufToFile(char *fileName, uint8_t * buf, size_t fileSz, int flags);

extern bool files_writeToFd(int fd, uint8_t * buf, size_t fileSz);

extern bool files_writeStrToFd(int fd, char *str);

extern ssize_t files_readFromFd(int fd, uint8_t * buf, size_t fileSz);

extern bool files_writePatternToFd(int fd, off_t size, unsigned char p);

extern bool files_exists(char *fileName);

extern const char *files_basename(char *fileName);

extern bool files_parseDictionary(honggfuzz_t * hfuzz);

extern bool files_copyFile(const char *source, const char *destination, bool * dstExists,
                           bool try_link);

extern bool files_parseBlacklist(honggfuzz_t * hfuzz);

extern uint8_t *files_mapFile(char *fileName, off_t * fileSz, int *fd, bool isWritable);

extern uint8_t *files_mapFileShared(char *fileName, off_t * fileSz, int *fd);

extern void *files_mapSharedMem(size_t sz, int *fd, const char *dir);

extern bool files_readPidFromFile(const char *fileName, pid_t * pidPtr);

extern size_t files_parseSymbolFilter(const char *inFIle, char ***filterList);

#endif
