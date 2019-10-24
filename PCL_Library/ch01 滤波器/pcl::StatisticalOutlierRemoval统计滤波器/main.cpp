//
// Created by zpw on 2019/10/10.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

int main(int argc, char **argv){

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PCDReader reader;

    reader.read<pcl::PointXYZ>("table_scene_lms400.pcd", *cloud);
    using std::cout;
    using std::endl;

    cout << "Cloud before filtering:  " << endl;
    cout << *cloud << endl;

    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;    //创建滤波器对象
    sor.setInputCloud(cloud);                       //设置呆滤波的点云
    sor.setMeanK(50);                                //设置在进行统计时考虑查询点临近点
    sor.setStddevMulThresh(1.0);               //设置判断是否为离群点的阀值
    sor.filter(*cloud_filtered);                       //执行滤波处理保存内点到cloud_filtered
    cout << "Cloud after filtering: " << endl;
    cout << *cloud_filtered << endl;
    pcl::PCDWriter writer;
    writer.write<pcl::PointXYZ>("table_scene_lms400_inliers.pcd", *cloud_filtered, false);
    sor.setNegative(true);
    sor.filter(*cloud_filtered);
    writer.write<pcl::PointXYZ>("table_scene_lms400_outliers.pcd", *cloud_filtered, false);


    return 0;
}




