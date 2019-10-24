#include <iostream>
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/extract_indices.h>


int main() {

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>),
                                        cloud_p (new pcl::PointCloud<pcl::PointXYZ>),
                                        cloud_f (new pcl::PointCloud<pcl::PointXYZ>),
                                        cloud_blob(new pcl::PointCloud<pcl::PointXYZ>),
                                        cloud_filter_blob(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PCDReader reader;
    reader.read("table_scene_lms400.pcd", *cloud_blob);
    std::cout << "PointCloud before filtering: " << cloud_blob->width * cloud_blob->height << " data points. "
              << std::endl;
    pcl::VoxelGrid<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud_blob);
    sor.setLeafSize(0.01f, 0.01f, 0.01f);
    sor.filter(*cloud_filter_blob);











    return 0;
}