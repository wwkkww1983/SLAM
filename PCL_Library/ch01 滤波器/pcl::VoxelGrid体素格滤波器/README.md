体素格滤波器VoxelGrid 下采样 在网格内减少点数量保证重心位置不变

在网格内减少点数量保证重心位置不变　 
下采样 同时去除 NAN点
  
  #include <pcl/filters/voxel_grid.h>

// 转换为模板点云 pcl::PointCloud<pcl::PointXYZ>
pcl::fromPCLPointCloud2 (*cloud_filtered_blob, *cloud_filtered);


  如果使用高分辨率相机等设备对点云进行采集，往往点云会较为密集。
  过多的点云数量会对后续分割工作带来困难。
  体素格滤波器可以达到向下采样同时不破坏点云本身几何结构的功能。
  点云几何结构 不仅是宏观的几何外形，也包括其微观的排列方式，
  比如横向相似的尺寸，纵向相同的距离。
  随机下采样虽然效率比体素滤波器高，但会破坏点云微观结构.

  使用体素化网格方法实现下采样，即减少点的数量 减少点云数据，
  并同时保存点云的形状特征，在提高配准，曲面重建，形状识别等算法速度中非常实用，
  PCL是实现的VoxelGrid类通过输入的点云数据创建一个三维体素栅格，
  容纳后每个体素内用体素中所有点的重心来近似显示体素中其他点，
  这样该体素内所有点都用一个重心点最终表示，对于所有体素处理后得到的过滤后的点云，
  这种方法比用体素中心（注意中心和重心）逼近的方法更慢，但是对于采样点对应曲面的表示更为准确。

  // 创建点云对象　指针
  pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2 ());
  pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());
  // 源点云读取　获取　后
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;  //创建滤波对象
    sor.setInputCloud (cloud);            　　　　//设置需要过滤的点云(指针)　给滤波对象
    sor.setLeafSize (0.01f, 0.01f, 0.01f);  　　//设置滤波时创建的体素体积为1cm的立方体
    sor.filter (*cloud_filtered);           　　//执行滤波处理，存储输出


//  Approximate 体素格滤波器VoxelGrid　
pcl::ApproximateVoxelGrid<pcl::PointXYZ> approximate_voxel_filter;
approximate_voxel_filter.setLeafSize (0.2, 0.2, 0.2);
approximate_voxel_filter.setInputCloud (input_cloud);// 第二次扫描点云数据作为源点云
approximate_voxel_filter.filter (*filtered_cloud);
std::cout << "Filtered cloud contains " << filtered_cloud->size ()
<< " data points from room_scan2.pcd" << std::endl;
