#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/filters/project_inliers.h>

int main() {

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    cloud->width = 5;
    cloud->height = 1;
    cloud->points.resize(cloud->width * cloud->height);
    for (auto & point : cloud->points){
        point.x = 1024 * rand() / (RAND_MAX + 1.0f);
        point.y = 1024 * rand() / (RAND_MAX + 1.0f);
        point.z = 1024 * rand() / (RAND_MAX + 1.0f);
    }
    std::cout << "Cloud before projection: " << std::endl;

    for (auto point : cloud->points){
        std::cout << "   " << point.x << " " << point.y << " " << point.z << std::endl;
    }

    //填充ModelCoefficients 的值 这里使用  ax + by + cz + d = 0 平面模型
    //a = b = d  = 0 c = 1  为x-y平面
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients());
    coefficients->values.resize(4);
    coefficients->values[0] = coefficients->values[1] = 0;
    coefficients->values[2] = 1.0;
    coefficients->values[3] = 0;

    //创建ProjectInliers对象 使用刚才定义好的ModelCoefficients 作为投影对象的模型
    pcl::ProjectInliers<pcl::PointXYZ> proj;                    //创建投影滤波对象
    proj.setModelType(pcl::SACMODEL_PLANE);                //设置对象投影模型为平面
    proj.setInputCloud(cloud);
    proj.setModelCoefficients(coefficients);               //设置模型对应的系数
    proj.filter(*cloud_filtered);                                //执行

    std::cout << "after projection " << std::endl;
    for (auto point : cloud_filtered->points){
        std::cout << "   " << point.x << " " << point.y << "  " << point.z << std::endl;
    }

    return 0;
}