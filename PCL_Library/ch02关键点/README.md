D点云关键点 /Keypoints ISS3D、 Harris3D、 NARF、SIFT3D 、简单下采样得到关键点
############################################################################
关键点也称为兴趣点，它是2D图像或是3D点云或者曲面模型上，
可以通过定义检测标准来获取的具有稳定性，
区别性的点集。

我们都知道在二维图像上，
有
    Harris、
    SIFT、
    SURF、
    KAZE
    
这样的关键点提取算法，
这种特征点的思想可以推广到三维空间。

关键点的数量相比于原始点云或图像的数据量减小很多，与局部特征描述子结合在一起，
组成　关键点描述子　常用来形成原始数据的表示，而且不失代表性和描述性，
从而加快了后续的识别，追踪等对数据的处理了速度，
故而，关键点技术成为在2D和3D 信息处理中非常关键的技术。
常见的三维点云关键点提取算法有一下几种：
    ISS3D、
    Harris3D、
    NARF、
    SIFT3D
这些算法在PCL库中都有实现，其中NARF算法是博主见过用的比较多的。

PCL—低层次视觉—关键点检测
关键点检测往往需要和特征提取联合在一起，
关键点检测的一个重要性质就是旋转不变性，
也就是说，物体旋转后还能够检测出对应的关键点。
不过说实话我觉的这个要求对机器人视觉来说是比较鸡肋的。
因为机器人采集到的三维点云并不是一个完整的物体，没哪个相机有透视功能。
机器人采集到的点云也只是一层薄薄的蒙皮。所谓的特征点又往往在变化剧烈的曲面区域，
那么从不同的视角来看，变化剧烈的曲面区域很难提取到同样的关键点。
想象一下一个人的面部，正面的时候鼻尖可以作为关键点，但是侧面的时候呢？
会有一部分面部在阴影中，模型和之前可能就完全不一样了。

也就是说现在这些关键点检测算法针对场景中较远的物体，
也就是物体旋转带来的影响被距离减弱的情况下，是好用的。
一旦距离近了，旋转往往造成捕获的仅有模型的侧面，关键点检测算法就有可能失效。


PCL中keypoints模块及类的介绍:
（1）class pcl::Keypoint<PointInT,PointOutT>  类keypoint是所有关键点检测相关类的基类，
定义基本接口，具体实现由子类来完成，
其继承关系时下图：

pcl::PCLBase<PointInT>
    |
    |___-> pcl::Keypoint<PointInT,PointOutT>
        |
        |
        |
        |___->pcl::AgastKeypoint2DBase<PointInT,PointOutT, pcl::common::IntensityFieldAccessor<PointInT >>
            ->pcl::AgastKeypoint2DBase<PointInT,PointOutT, IntensityT >
            ->pcl::BriskKeypoint2D<PointInT,PointOutT, IntensityT >
            ->pcl::HarrisKeypoint2D<PointInT,PointOutT, IntensityT >
            ->pcl::HarrisKeypoint3D<PointInT,PointOutT, IntensityT >
            ->pcl::HarrisKeypoint6D<PointInT,PointOutT, IntensityT >
            ->pcl::ISSKeypoint3D<PointInT,PointOutT, IntensityT >
            ->pcl::SIFTKeypoint<PointInT,PointOutT >
            ->pcl::SUSANKeypoint<PointInT,PointOutT, NormalT, IntensityT >
            ->pcl::TrajkovicKeypoint2D<PointInT,PointOutT, IntensityT >
            ->pcl::TrajkovicKeypoint3D<PointInT,PointOutT, IntensityT >

方法：
virtual void setSearchSurface (const PointCloudInConstPtr &cloud)
    设置搜索时所用搜索点云，cloud为指向点云对象的指针引用
void  	setSearchMethod (const KdTreePtr &tree)  
    设置内部算法实现时所用的搜索对象，tree为指向kdtree或者octree对应的指针
void  	setKSearch (int k)   
    设置K近邻搜索时所用的K参数
void  	setRadiusSearch (double radius)   
    设置半径搜索的半径的参数
int  	searchForNeighbors (int index, double parameter, std::vector< int > &indices, std::vector< float > &distances) const
    采用setSearchMethod设置搜索对象，以及setSearchSurface设置搜索点云，进行近邻搜索，返回近邻在点云中的索引向量，
    indices以及对应的距离向量distance其中为查询点的索引，parameter为搜索时所用的参数半径或者K



1. class pcl::HarrisKeypoint2D<PointInT,PointOutT,IntensityT>
     类HarrisKeypoint2D实现基于点云的强度字段的harris关键点检测子，其中包括多种不同的harris关键点检测算法的变种，其关键函数的说明如下：
    HarrisKeypoint2D (ResponseMethod method=HARRIS, 
              int window_width=3, 
              int window_height=3, 
              int min_distance=5, 
              float threshold=0.0)

    重构函数，method需要设置采样哪种关键点检测方法，有HARRIS，NOBLE，LOWE，WOMASI四种方法，默认为HARRIS，
        window_width  window_height为检测窗口的宽度和高度
        min_distance 为两个关键点之间 容许的最小距离，
        threshold为判断是否为关键点的感兴趣程度的阀值，小于该阀值的点忽略，大于则认为是关键点

void  	setMethod (ResponseMethod type)     
    设置检测方式
void  	setWindowWidth (int window_width)   
    设置检测窗口的宽度
void  	setWindowHeight (int window_height) 
    设置检测窗口的高度
void  	setSkippedPixels (int skipped_pixels)   
    设置在检测时每次跳过的像素的数目
void  	setMinimalDistance (int min_distance)   
    设置候选关键点之间的最小距离
void  	setThreshold (float threshold)  	    
    设置感兴趣的阀值
void  	setNonMaxSupression (bool=false)  	    
    设置是否对小于感兴趣阀值的点进行剔除，如果是true则剔除,否则返回这个点
void  	setRefine (bool do_refine)		
    设置是否对所得的关键点结果进行优化，
void  	setNumberOfThreads (unsigned int nr_threads=0)  
    设置该算法如果采用openMP并行机制，能够创建线程数目





















