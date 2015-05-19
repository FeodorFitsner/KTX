/* -*- tab-width: 4; -*- */
/* vi: set sw=2 ts=4: */

/* $Id: ac63511da134f2c25a9e1da86a36bc27b6198ae3 $ */

/**
 * @internal
 * @file LoadTestsGL3.h
 * @~English
 *
 * @brief Declaration of LoadTests app for OpenGL 3.3+ and OpenGL ES 3.x
 *
 * @author Mark Callow
 * @copyright (c) 2015, Mark Callow.
 */

/*
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * unaltered in all copies or substantial portions of the Materials.
 * Any additions, deletions, or changes to the original source files
 * must be clearly indicated in accompanying documentation.
 *
 * If only executable code is distributed, then the accompanying
 * documentation must state that "this software is based in part on the
 * work of HI Corporation."
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 */


#include "../appfwSDL/AppBaseSDL.h"
#include "../common/at.h"
#include <string>

class LoadTestsGL3 : public AppBaseSDL {
  public:
    LoadTestsGL3();
    virtual int doEvent(void* userdata, SDL_Event* event);
    virtual void finalize();
    virtual bool initialize(int argc, char* argv[]);
    virtual void onFPSUpdate();
    virtual void resize(int width, int height);
    virtual void update(void* userdata, int ticks);

  protected:
    /** A table of samples and arguments */
    typedef struct sampleInvocation_ {
        const atSample* sample;
        const std::string args;
        const char* const title;
    } sampleInvocation;
    
    void invokeSample(int iSampleNum);
    void setWindowTitle(const char* const sampleName);
    SDL_Window* pswMainWindow;
    SDL_GLContext sgcGLContext;
    int iCurSampleNum;
    const sampleInvocation* pCurSampleInv;
    void* pCurSampleData;
    const char* szBasePath;

    static const sampleInvocation siSamples[];
    static const int iNumSamples;
    static const char* const szName;
};
