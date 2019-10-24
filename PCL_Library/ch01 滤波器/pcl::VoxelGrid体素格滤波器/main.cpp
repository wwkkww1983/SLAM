//
// Created by zpw on 2019/10/10.
//
//此示例用来演示VoxelGrid滤波器对点云进行下采样
//减少点云的数量,减少点云数据,并同时保持点云形状特征
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>


int main() {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    //点云未处理之前 查看共有多少个点
    pcl::PCDReader reader;
    reader.read("table_scene_lms400.pcd", *cloud);
    std::cout << "PointCloud before filtering: " << cloud->width * cloud->height << " data points ( "
              << pcl::getFieldsList(*cloud) << " ).";

    pcl::VoxelGrid<pcl::PointXYZ> sor;                           //创建滤波对象
    sor.setInputCloud(cloud);                              //给滤波对象设置需要过滤的点云
    sor.setLeafSize(0.01f, 0.01f, 0.01f);               //设置滤波时创建的像素大小为1cm立方体
    sor.filter(*cloud_filtered);
    std::cout << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height
              << " data points (" << pcl::getFieldsList(*cloud_filtered) << ").";
    pcl::PCDWriter writer;
    writer.write("2f.pcd", *cloud_filtered);


    return 0;
}

