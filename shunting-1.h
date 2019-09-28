#ifndef SHUNTING_H
#define SHUNTING_H

#include <iostream>
#include"queue.h"
#include"stack.h"
#include"token.h"
#include"number.h"
#include"operator.h"
#include "math.h"
#include "variables.h"

using namespace std;

Queue<Token*> Input(string s);
double RPN(Queue<Token *> MyQueue, double x_value);
Queue <Token*> shunting(Queue<Token *> MyQueue);
void Removeexcess(Queue<Token*> & MyQueue);
Queue<Token*> shuntingchanges(Queue<Token*>  MyQueue);

void RealToPix(double &x, double &y, double NumOfPoints, double scaleX, double scaleY);//change 1000 to the constant screenwidth/height
//void Graph(Queue<Token*> MyQueue, double MinX,double MaxX,double MinY,double MaxY);

const double e=2.718281828459045;

#endif // SHUNTING_H
