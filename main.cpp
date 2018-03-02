

#include <osg/GLExtensions>
#include <osg/Node>
#include <osg/Geometry>
#include <osg/Notify>
#include <osg/MatrixTransform>
#include <osg/Texture2D>
#include <osg/Stencil>
#include <osg/ColorMask>
#include <osg/Depth>
#include <osg/Billboard>
#include <osg/Material>
#include <osg/Projection>
#include <osg/TextureCubeMap>
#include <osg/io_utils>


#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>

#include <osgUtil/SmoothingVisitor>

#include <osgDB/Registry>
#include <osgDB/ReadFile>

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <iostream>


int main(int argc, char** argv)
{

	osg::ArgumentParser* arguments = new osg::ArgumentParser(&argc,argv);
	
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer();  

	osg::ref_ptr<osg::Group> root = new osg::Group;

	
	root->addChild(root);	


	viewer->setSceneData( root );
	osgGA::KeySwitchMatrixManipulator*  keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

    // set up the camera manipulators.
    keyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
    keyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );

	viewer->setCameraManipulator( keyswitchManipulator );

	viewer->addEventHandler(new osgViewer::StatsHandler);
    viewer->addEventHandler(new osgViewer::WindowSizeHandler);
    viewer->addEventHandler(new osgViewer::ThreadingHandler);
    viewer->addEventHandler(new osgViewer::HelpHandler);
    viewer->addEventHandler(new osgViewer::RecordCameraPathHandler);
    viewer->addEventHandler(new osgGA::StateSetManipulator(viewer->getCamera()->getOrCreateStateSet()));
 	viewer->realize();

	osgViewer::Viewer::Windows windows;
    viewer->getWindows(windows);
	
    	for(osgViewer::Viewer::Windows::iterator itr = windows.begin();
        itr != windows.end();
        ++itr)
    	{
            osg::State *s=(*itr)->getState();
        	s->setUseModelViewAndProjectionUniforms(true);
            s->setUseVertexAttributeAliasing(true);
    	}
       
       
    	
    	
    	
    return viewer->run();

};

