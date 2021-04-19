// Copyright 2021 by Liza
#include "TimedDoor.h"
#include <iostream>
#include <string>
#include <time.h>
DoorTimerAdapter::DoorTimerAdapter(TimedDoor& door_) : door(door_) {
this->door = door_;}
void DoorTimerAdapter::Timeout() {
door.DoorTimeOut();}
TimedDoor::TimedDoor(int time_) {
iTimeout = time_;
opened = false;
adapter = new DoorTimerAdapter(*this);}
bool TimedDoor::isDoorOpened() {
return opened;}
void TimedDoor::unlock() {
opened = true;
adapter->Timeout();}
void TimedDoor::lock() {
opened = false;}
void TimedDoor::DoorTimeOut() {
throw std::string("close the door!");}
void TimedDoor::throwState() {
if (opened) {
throw std::string("the door is opened!");}
else
{throw std::string("the door is closed!");}}
void Timer::sleep(int iTimeout) {
time_t start = time(nullptr);
while (time(nullptr) - start < iTimeout) {
continue;}}
void Timer::tregister(int iTimeout, TimerClient* tclient) {
this->client = tclient;
sleep(iTimeout);
tclient->Timeout();}
