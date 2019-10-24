
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/console/parse.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/sac_model_plane.h>            //平面模型
#include <pcl/sample_consensus/sac_model_sphere.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>

using namespace std;

boost::shared_ptr<pcl::visualization::PCLVisualizer>
simpleVis(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud){

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor (0, 0, 0);
    viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
    //viewer->addCoordinateSystem (1.0);
    viewer->initCameraParameters ();
    return (viewer);
}

int main() {

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);









    return 0;
}