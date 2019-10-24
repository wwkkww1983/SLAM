//
// Created by zpw on 2019/10/10.
//
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>

int main(int argc, char** argv){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    cloud->width = 5;
    cloud->height = 1;
    cloud->points.resize(cloud->width * cloud->height);
    for (auto & point : cloud->points){
        point.x = 1024 * rand() / (RAND_MAX + 1.0f);
        point.x = 1024 * rand() / (RAND_MAX + 1.0f);
        point.x = 1024 * rand() / (RAND_MAX + 1.0f);
    }
    char model;
    std::cout << "which model do you want to choose c or r" << std::endl;
    std::cin >> model;
    if (model == 'c'){
        //定义条件对象
        pcl::ConditionAnd<pcl::PointXYZ>::Ptr range_cond (new pcl::ConditionAnd<pcl::PointXYZ>());
        //添加在z字段上大于0的比较算子
        range_cond->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr
        (new pcl::FieldComparison<pcl::PointXYZ>("z", pcl::ComparisonOps::GT, 0.0)));
        //添加在z字段上小于0.8的比较算子
        range_cond->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(
                new pcl::FieldComparison<pcl::PointXYZ>("z", pcl::ComparisonOps::LT, 0.8)));
        //创建滤波器对象并用条件定义对象初始化
        pcl::ConditionalRemoval<pcl::PointXYZ> condrem(range_cond);
        condrem.setInputCloud(cloud);         //设置输入点云
        condrem.setKeepOrganized(true);         //设置保持点云的结构
        condrem.filter(*cloud_filtered);         //执行条件滤波存储结果到cloud_filtered
    }
    else if(model == 'r'){
        pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;    //创建滤波器
        outrem.setInputCloud(cloud);                  //设置输入点云
        outrem.setRadiusSearch(0.8);                  //设置在0.8半径的范围内查找临近点
        outrem.setMinNeighborsInRadius(2);           //设置查询点的邻近点集数小于2删除
        outrem.filter(*cloud_filtered);
    }
    else{
        std::cout << "you have input wrong election " << std::endl;
    }
    std::cout << "original cloud" << std::endl;
    for (auto point : cloud->points){
        std::cout <<  "    "  << point.x  << " " << point.y << " " << point.z << std::endl;
    }
    std::cout << "after filter cloud " << std::endl;
    for (auto point : cloud_filtered->points){
        std::cout << "   " << point.x << " " << point.y << " " << point.z << std::endl;
    }


    return 0;
}
