直通滤波器pcl::PassThrough 直接指定保留哪个轴上的范围内的点

  #include <pcl/filters/passthrough.h>
  如果使用线结构光扫描的方式采集点云，必然物体沿z向分布较广，
  但x,y向的分布处于有限范围内。
  此时可使用直通滤波器，确定点云在x或y方向上的范围，
  可较快剪除离群点，达到第一步粗处理的目的。

  // 创建点云对象　指针
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  // 原点云获取后进行滤波
  pcl::PassThrough<pcl::PointXYZ> pass;// 创建滤波器对象
  pass.setInputCloud (cloud);//设置输入点云
  pass.setFilterFieldName ("z");//滤波字段名被设置为Z轴方向
  pass.setFilterLimits (0.0, 1.0);//可接受的范围为（0.0，1.0） 
  pass.setFilterLimitsNegative (true);//设置保留范围内 还是 过滤掉范围内
  //true 表示将当前设置范围内的点云数据过滤掉
  pass.filter (*cloud_filtered); //执行滤波，保存过滤结果在cloud_filtered
