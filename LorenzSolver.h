/*
 LorenzSolver.h
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

#ifndef _LORENZSOLVER_H_
#define _LORENZSOLVER_H_

//////////////////
//Include something here that provides an implementation of Vec3f
//(using cinder here)
#include "cinder/app/AppBasic.h"
using namespace ci;
//////////////////

// Computes numerical solutions to the Lorenz diff eq. using the Runge-Kutta method.
class LorenzSolver{
public:
    LorenzSolver(float d=0.01f, float s=10.f, float b=8.f/3.f, float r=28.f);
    
    //compute the next coordinates in the system for the given point
    Vec3f computePoint(Vec3f);
    
    void setDelta(float newDelta){this->delta+= newDelta;};
    void setSigma(float newSigma){this->sigma+= newSigma;};
    void setBeta(float newBeta){this->beta+= newBeta;};
    void setRho(float newRho){this->rho+= newRho;};

    float getDelta(){return this->delta;};
    float getSigma(){return this->sigma;};
    float getBeta(){return this->beta;};
    float getRho(){return this->rho;};

private:

    void computeA();
    void computeB();
    void computeC();
    void computeD();
    
    float f1(float, float, float);
    float f2(float, float, float);
    float f3(float, float, float);
    
    float delta;
    float sigma;
    float beta;
    float rho;
    
    Vec3f oldPoint;
    
    Vec3f A;
    Vec3f B;
    Vec3f C;
    Vec3f D;
};

#endif
