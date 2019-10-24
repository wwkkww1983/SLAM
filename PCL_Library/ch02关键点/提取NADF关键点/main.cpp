#include <iostream>
#include <boost/thread/thread.hpp>
#include <pcl/range_image/range_image.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/range_image_visualizer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/range_image_border_extractor.h>
#include <pcl/keypoints/narf_keypoint.h>
#include <pcl/console/parse.h>

using Type = pcl::PointXYZ;

float angular_result = 0.5f;
float angular_resolution = 0.5f;
float support_size = 0.2f;
pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
bool setUnseenToMaxRange = false;
void printUsage(const char* progName){
    std::cout << "\n\nUsage: " << progName << " [options] <scene.pcd>\n\n "
            <<"Options:\n"
            <<"-------------------------------------------\n"
            <<"-r <float>   angular resolution in degrees (default "<<angular_resolution<<")\n"
            <<"-c <int>     coordinate frame (default "<< (int)coordinate_frame <<")\n"
            <<"-m           Treat all unseen points as maximum range readings\n"
            <<"-s <float>   support size for the interest points (diameter of the used sphere - "
            <<"default "<< support_size <<")\n"
            <<"-h           this help\n"
            <<"\n\n";
}

void setViewerPose(pcl::visualization::PCLVisualizer &viewer,const Eigen::Affine3f & viewer_pose)
 {
     Eigen::Vector3fpos_vector=viewer_pose*Eigen::Vector3f(0,0,0);
     Eigen::Vector3flook_at_vector=viewer_pose.rotation()*Eigen::Vector3f(0,0,1)+pos_vector;
     Eigen::Vector3fup_vector=viewer_pose.rotation()*Eigen::Vector3f(0,-1,0);
     viewer.camera_.pos[0]=pos_vector[0];
     viewer.camera_.pos[1]=pos_vector[1];
     viewer.camera_.pos[2]=pos_vector[2];
     viewer.camera_.focal[0]=look_at_vector[0];
     viewer.camera_.focal[1]=look_at_vector[1];
     viewer.camera_.focal[2]=look_at_vector[2];
     viewer.camera_.view[0]=up_vector[0];
     viewer.camera_.view[1]=up_vector[1];
     viewer.camera_.view[2]=up_vector[2];
     viewer.updateCamera();
 }



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}