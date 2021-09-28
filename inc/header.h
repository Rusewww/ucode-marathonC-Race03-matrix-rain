#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

void mx_printerr(const char *s);
int mx_strlen(const char *s);
void intro(void);
void mx_rain(int lang);
wchar_t mx_get_random_jp();
wchar_t mx_get_random_russ();














