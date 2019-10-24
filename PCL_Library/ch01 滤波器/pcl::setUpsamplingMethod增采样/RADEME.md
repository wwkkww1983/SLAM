增采样是一种表面重建方法，当你有比你想象的要少的点云数据时，
  增采样可以帮你恢复原有的表面（S），通过内插你目前拥有的点云数据，
  这是一个复杂的猜想假设的过程。所以构建的结果不会百分之一百准确，
  但有时它是一种可选择的方案。
  所以，在你的点云云进行下采样时，一定要保存一份原始数据！
  #include <pcl/surface/mls.h>
  ------------
  // 滤波对象
      pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ> filter;
      filter.setInputCloud(cloud);
      //建立搜索对象
      pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree;
      filter.setSearchMethod(kdtree);
      //设置搜索邻域的半径为3cm
      filter.setSearchRadius(0.03);
      // Upsampling 采样的方法有 DISTINCT_CLOUD, RANDOM_UNIFORM_DENSITY
      filter.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ>::SAMPLE_LOCAL_PLANE);
      // 采样的半径是
      filter.setUpsamplingRadius(0.03);
      // 采样步数的大小
      filter.setUpsamplingStepSize(0.02);

      filter.process(*filteredCloud);
