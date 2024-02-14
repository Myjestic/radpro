/*
 * Rad Pro
 * Data logging
 *
 * (C) 2022-2024 Gissio
 *
 * License: MIT
 */

#if !defined(DATALOG_H)
#define DATALOG_H

#include <stdbool.h>
#include <stdint.h>

#include "settings.h"
#include "view.h"

extern const View datalogMenuView;

void initDatalog(void);

void updateDatalog(void);
void writeDatalog(void);
void lockDatalog(void);
void unlockDatalog(void);

void startDatalogDownload(void);
bool getDatalogDownloadEntry(Dose *dose);

#endif
