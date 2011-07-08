/*
 LorenzSolver.cpp
 Created by Guillaume Ardaud on 7/7/11. guillaume@panafold.com
 Copyright 2011 Panafold. All rights reserved.

 Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 software and associated documentation files (the "Software"), to deal in the Software 
 without restriction, including without limitation the rights to use, copy, modify, 
 merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
 permit persons to whom the Software is furnished to do so, subject to the following 
 conditions:
 
 The above copyright notice and this permission notice shall be included in 
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
 OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 IN THE SOFTWARE.

 */

#include "LorenzSolver.h"

LorenzSolver::LorenzSolver(float d, float s, float b, float r){
    this->delta=d;
    this->sigma=s;
    this->beta=b;
    this->rho=r;
}

Vec3f LorenzSolver::computePoint(Vec3f oldPoint){
    this->oldPoint= oldPoint;
    
    Vec3f newPoint;
    
    this->computeA();
    this->computeB();
    this->computeC();
    this->computeD();
    
    newPoint.x= oldPoint.x + (this->A.x+this->B.x*2+this->C.x*2+this->D.x) * this->delta/6.0f;
    newPoint.y= oldPoint.y + (this->A.y+this->B.y*2+this->C.y*2+this->D.y) * this->delta/6.0f;
    newPoint.z= oldPoint.z + (this->A.z+this->B.z*2+this->C.z*2+this->D.z) * this->delta/6.0f;
    
    return newPoint;
}

void LorenzSolver::computeA(){
    this->A.x= f1(0.0f,0.0f,0.0f);
    this->A.y= f2(0.0f,0.0f,0.0f);
    this->A.z= f3(0.0f,0.0f,0.0f);
}

void LorenzSolver::computeB(){
    this->B.x= f1(this->A.x,this->A.y,this->A.z);
    this->B.y= f2(this->A.x,this->A.y,this->A.z);
    this->B.z= f3(this->A.x,this->A.y,this->A.z);
}

void LorenzSolver::computeC(){
    this->C.x= f1(this->B.x,this->B.y,this->B.z);
    this->C.y= f2(this->B.x,this->B.y,this->B.z);
    this->C.z= f3(this->B.x,this->B.y,this->B.z);
}

void LorenzSolver::computeD(){
    this->D.x= f1(this->C.x,this->C.y,this->C.z);
    this->D.y= f2(this->C.x,this->C.y,this->C.z);
    this->D.z= f3(this->C.x,this->C.y,this->C.z);
}

float LorenzSolver::f1(float p1, float p2, float p3){
    float r= this->sigma * (this->oldPoint.y + p2 * this->delta/2 - (this->oldPoint.x + p1 * this->delta/2));

    return r;
}

float LorenzSolver::f2(float p1, float p2, float p3){
    float r= -1*(this->oldPoint.x + p1 * this->delta/2) * (this->oldPoint.z + p3 * delta/2) + this->rho * (this->oldPoint.x+p1*this->delta/2)-(this->oldPoint.y+p2*this->delta/2);
    
    return r;
}

float LorenzSolver::f3(float p1, float p2, float p3){
    float r= (this->oldPoint.x + p1 * this->delta/2) * (this->oldPoint.y + p2 * delta/2) - this->beta * (this->oldPoint.z+p3*this->delta/2);
    
    return r;
}