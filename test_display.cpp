// ****************************************************************************
//  test_display.cpp                                                Tao project
// ****************************************************************************
//
//   File Description:
//
//    Tao display module to test presentation in offline mode.
//
//
//
//
//
//
//
// ****************************************************************************
// This software is property of Taodyne SAS - Confidential
// Ce logiciel est la propriété de Taodyne SAS - Confidentiel
//  (C) 2012 Catherine BURVELLE <Catherine@taodyne.com>
//  (C) 2012 Taodyne SAS
// ****************************************************************************

#include "test_display.h"
#include <tao/tao_gl.h>
#include "widget_tests.h"
#include "tao_utf8.h"
#include "graphic_state.h"
#include "../tao_synchro/event_capture.h"

DLL_PUBLIC Tao::GraphicState * graphic_state = NULL;


test_display::test_display(int w, int h)
// ----------------------------------------------------------------------------
//   Create a display context
// ----------------------------------------------------------------------------
    : w(w), h(h), shot(false)
{
    frame = synchroBasic::tao->newFrameBufferObject(w, h);
}


test_display::~test_display()
// ----------------------------------------------------------------------------
//   Delete display context
// ----------------------------------------------------------------------------
{
    IFTRACE(displaymode)
        debug() << "Deleting framebuffer\n";
    synchroBasic::tao->deleteFrameBufferObject(frame);
}


void test_display::display(void *obj)
// ----------------------------------------------------------------------------
//   Rendering in 2D+Depth mode
// ----------------------------------------------------------------------------
{
    IFTRACE(displaymode)
        debug() << "->test_display::display \n";
    test_display * instance = (test_display *)obj;
    instance->do_display();
}


void test_display::do_display()
// ----------------------------------------------------------------------------
//    Another rendering
// ----------------------------------------------------------------------------
{
    // Save current framebuffer, if any
    GLint fbname = 0;
    GL.Get(GL_FRAMEBUFFER_BINDING, &fbname);

    // Read output resolution
    int w = synchroBasic::base->winSize.width();
    int h = synchroBasic::base->winSize.height();

    // Make sure output buffer has the right size (resolution may have changed)
    // and prepare to draw into it
    resize(w, h);
    synchroBasic::tao->bindFrameBufferObject(frame);

    // (1) Normal rendering into the FBO.

    // Setup viewport: rendering to full FBO size.
    GL.Viewport(0, 0, w, h);

    synchroBasic::tao->doMouseTracking(true);
    synchroBasic::tao->setMouseTrackingViewport(0, 0, w, h);

    // Clear draw buffer
    synchroBasic::tao->setGlClearColor();
    GL.Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup projection and modelview matrices
    synchroBasic::tao->setProjectionMatrix(w, h, 1, 1);
    synchroBasic::tao->setModelViewMatrix(1, 1);

    // Set suitable GL parameters for drawing
    synchroBasic::tao->setupGl();
    GL.BlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,
                         GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    // Draw scene, selection and activities
    synchroBasic::tao->drawScene();
    synchroBasic::tao->drawSelection();
    synchroBasic::tao->drawActivities();
    synchroBasic::tao->releaseFrameBufferObject(frame);

    WidgetTests * player = dynamic_cast<WidgetTests *>
            (synchroBasic::base->tao_event_handler);
    if (player && player->shotImage)
    {
        IFTRACE(displaymode)
                debug() << "..test_display::display IMAGE SHOT\n";
        *(player->shotImage) = (QImage *)
                synchroBasic::tao->imageFromFrameBufferObject(frame);
        player->shotImage = NULL;
    }

    // (2) Render a full-screen quad

    synchroBasic::tao->frameBufferObjectToTexture(frame);


    // Select draw buffer
    if (fbname)
        GL.BindFramebuffer(GL_FRAMEBUFFER, fbname);
    else
        GL.DrawBuffer(GL_BACK);

    // (2) Render a full-screen quad

    // Set viewport for full screen
    GL.Viewport(0, 0, w, h);

    // Clear draw buffer
    GL.ClearColor(0, 0, 0, 1);
    GL.Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GL.Disable(GL_BLEND);

    // CHECK
    // Not sure why, but without this I often have a blank screen
    GL.Disable(GL_POLYGON_OFFSET_FILL);
    GL.Disable(GL_POLYGON_OFFSET_LINE);
    GL.Disable(GL_POLYGON_OFFSET_POINT);

    GL.MatrixMode(GL_PROJECTION);
    GL.LoadIdentity();
    GL.MatrixMode(GL_MODELVIEW);
    GL.LoadIdentity();

    GL.Begin(GL_QUADS);
    GL.TexCoord( 0 , 0);
    GL.Vertex  (-1, -1);
    GL.TexCoord( 1 , 0);
    GL.Vertex  ( 1, -1);
    GL.TexCoord( 1,  1);
    GL.Vertex  ( 1,  1);
    GL.TexCoord( 0,  1);
    GL.Vertex  (-1,  1);
    GL.End();

    IFTRACE(displaymode)
            debug() << "<-test_display::display \n";

}


void * test_display::use()
// ----------------------------------------------------------------------------
//   Display mode is about to be used: create instance of display object
// ----------------------------------------------------------------------------
{
    QString msg = QObject::tr("TestDisplay");
    synchroBasic::tao->setWatermarkText(+msg, 400, 200);

    int w = synchroBasic::base->winSize.width();
    int h = synchroBasic::base->winSize.height();
    test_display * instance = new  test_display(w, h);
    IFTRACE(displaymode)
        debug() << "test_display::use\n";

    return instance;
}


void test_display::resize(int w, int h)
// ----------------------------------------------------------------------------
//   Resize the frame buffer if needed
// ----------------------------------------------------------------------------
{
    if (this->w == 0 && this->h == 0)
    {
        IFTRACE(displaymode)
            debug() << "Allocating framebuffer: "
                    << w << "x" << h << "\n";
        frame = synchroBasic::tao->newFrameBufferObject(w, h);
    }
    else
    {
        if (w != this->w || h != this->h)
        {
            IFTRACE(displaymode)
                debug() << "Resizing framebuffer: "
                        << w << "x" << h << "\n";
            synchroBasic::tao->resizeFrameBufferObject(frame, w, h);
        }
    }
    this->w = w;
    this->h = h;
}


std::ostream & test_display::debug()
// ----------------------------------------------------------------------------
//   Convenience method to log with a common prefix
// ----------------------------------------------------------------------------
{
    std::cerr << "[test_display] ";
    return std::cerr;
}


void test_display::unuse(void *obj)
// ----------------------------------------------------------------------------
//   Delete data allocated in use function
// ----------------------------------------------------------------------------
{
    test_display * o = (test_display *)obj;
    if (o)
        delete o;
}
