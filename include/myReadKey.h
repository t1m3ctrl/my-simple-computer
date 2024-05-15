#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <termios.h>
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

int rk_readKey (enum keys *key);
int rk_myTermSave (void);
int rk_myTermRestore (void);
int rk_myTermRegime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readvalue (int *value, int timeout);