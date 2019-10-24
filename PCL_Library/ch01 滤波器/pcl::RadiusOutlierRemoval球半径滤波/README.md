球半径滤波器 去除离群点 去除离散点 pcl::RadiusOutlierRemoval
#include <pcl/filters/radius_outlier_removal.h>

球半径滤波器与统计滤波器相比更加简单粗暴
以某点为中心 画一个球计算落在该球内的点的数量，当数量大于给定值时，
则保留该点，数量小于给定值则剔除该点
此算法运行速度快 依序迭代留下的点一定是最密集的
但球的半径与球内点的数目都需要人工指定

// 创建点云对象　指针
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  // 源点云读取　获取　后

  pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;  //创建滤波器
  outrem.setInputCloud(cloud);    //设置输入点云
  outrem.setRadiusSearch(0.8);    //设置半径为0.8的范围内找临近点
  outrem.setMinNeighborsInRadius (2);//设置查询点的邻域点集数小于2的删除
      // apply filter
  outrem.filter (*cloud_filtered);//执行条件滤波  在半径为0.8 在此半径内必须要有两个邻居点，此点才会保存
