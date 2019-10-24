//本例使用直通滤波器进行滤波处理
//直通滤波器用来将某个坐标轴 范围以外的点删除
#include <iostream>
#include <ctime>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>

int main() {
    srand((unsigned)time(nullptr));
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    cloud->width = 5;
    cloud->height = 1;
    cloud->points.resize(cloud->width * cloud->height);

    for (auto &i : cloud->points){
        i.x = rand() / (RAND_MAX + 1.0f) - 0.5;
        i.y = rand() / (RAND_MAX + 1.0f) - 0.5;
        i.z = rand() / (RAND_MAX + 1.0f) - 0.5;
    }
    std::cout << "Cloud before filtering: " << std::endl;
    for (auto i : cloud->points){
        std::cout << "   " << i.x << " " << i.y << " " << i.z << std::endl;
    }
    //创建智通滤波器对象 滤波方向设定为Z方向 可接受的范围为(0, 0, 1.0)
    //将点云中所有的点的Z坐标不在该范围的点过滤掉或者保留 true 表示过滤掉 false表示保留
    pcl::PassThrough<pcl::PointXYZ> pass;               //设置滤波器对象
    pass.setInputCloud(cloud);                    //设置输入点云
    pass.setFilterFieldName("z");             //设置过滤时所需要的点云类型的z字段
    pass.setFilterLimits(0.0, 1.0);   //设置在过滤字段上的范围
    pass.setFilterLimitsNegative(true);               //设置保留范围内的还是过滤掉范围内的
    pass.filter(*cloud_filtered);                    //执行滤波，保存过滤结果在cloud_filter


    std::cout << "Cloud after filtering " << std::endl;
    for (auto i : cloud_filtered->points){
        std::cout << "    " << i.x << " " << i.y << " " << i.z << std::endl;
    }


    return 0;
}