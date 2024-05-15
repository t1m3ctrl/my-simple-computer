#pragma once
#include <rk_structs.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

enum keys
{
  UP,
  RIGHT,
  DOWN,
  LEFT,
  LOAD,
  SAVE,
  RESET,
  RUN,
  STEP,
  ENTER,
  F5,
  F6,
  EXIT,
  ERROR
};

int rk_readKey (enum keys *);
int rk_myTermSave (void);
int rk_myTermRestore (void);
int rk_myTermRegime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readValue (int *value, int timeout);