SLAM定义
	Localization: 在给定地图的情况下，估计机器人的位资。 (在移动机器人导航中最重要也是最难得部分)
	Mapping: 在给定机器人的位资的情况下，估计环境地图。   可以不实时
	SLAM: 同时估计机器人的位资和环境地图。               移动机器人中最重要的内容
SLAM要解决的问题
	机器人在环境中的位资。
	导航过程中需要的环境地图。
基于后端的分类
			类型												特点

	图优化的方法(Graph-based)							估计全部位资(最通用，当发现以前所构建的地图有错误会及时修正)
														可以想像估计的区间无穷大
	滑动窗口方法(sliding-window)							估计固定数量的位资(VIO,VO) 估计一段区间
	滤波器方法(filter-based)                             估计当前位资(Pose-Fusion) 只估计一个当前位置一个点(以前的错了不管了)



基于图优化(Graph-based) SLAM的框架
	Graph-based SLAM
	前端匹配(局部匹配、帧间匹配)
	回环检测
	后端优化

图的结构
	Graph: 表示SLAM的过程
	Node:  机器人的位资
	Edge:  节点之间的空间约束关系


激光slam的pipline大致如下:
	1.数据处理(激光雷达去畸变、里程计标定)				
	2.激光帧间匹配(计算两帧激光之间的相对位资)
	3.激光回环检测(识别回到访问过的环境)
	4.后端优化(Pose-Graph、非线性最小二乘法优化)
	
	传感器 -> 传感器数据处理 -> 前段匹配 -> 回环检测 -> 后端优化 -> 地图构建


对传感器的数据处理非常重要
	1.里程计标定
		机械标称值不代表实际值、实际误差可能较大
		里程计的精度对于机器人定位和建图非常重要
	2.激光雷达运动畸变去除
		一帧激光数据的采集需要时间
		运动畸变会让数据严重失真、影响匹配精度

激光雷达的帧间匹配算法-----核心部分
	常用的算法如下
	ICP家族													其他
	ICP(Iterative Closest Point)							CSM(Correlation Scan Match)暴力搜索
	PI-ICP(Point-to-Line Iterative Closeest Point)			NDT(Normal Distance Transform)高斯分布进行匹配
	NICP(Normal Iterative Closest Point)					Optimization-Based优化
															Feature-Based特征(类似于视觉slam主要用在三维激光点云)

	3.回环检测(识别到过去的地方)
				方法																	特点
			Scan-to-Scan(当前帧激光数据与前面采集过的帧数据进行匹配)			计算量最小，容易产生歧义
			Scan-to-Map(将前面的数据划分为子图，然后用当前帧的数据进行匹配)	计算量中等，中等歧义
			Map-to-Map(新采集到的几帧数据组成子图与前面的子图进行匹配)         计算量最大，基本不产生歧义
	4.后端优化方法(非线性最小二乘问题)
		高斯牛顿方法   HX = b
		LM方法        (H + LI)X = b


2D激光SLAM
	2D激光SLAM的输入
		IMU数据(可选)
		里程计数据
		2D激光雷达的数据
	2D激光SLAM的输出
		覆盖珊格地图
		机器人的轨迹 or PoseGraph

	2D激光SLAM的帧间匹配算法(常用)
		PL-ICP(Point-to-Line ICP)    点到线的距离，更符合室内结构化场景，依赖初始解

		CSM(Correlation Scan Match)  暴力搜索，能找到最优解

		Optimization-Based           依赖于地图的梯度，可以轻易的引入额外约束

	2D激光SLAM的回环检测方法
		Scan-to-Map
		Map-to-Map
		Branch and Bound & Lazy Decision
		State of Art: CSM + 梯度优化

	2D激光SLAM的发展
		Filter-based(基于粒子滤波)
		方法                          特点
	  EKF-SLAM(90年代)           随着环境的增大，状态量将会急剧增大
	  FastSLAM(02-03)            粒子滤波，每一个粒子表示一个地图
	  Gmapping(07)               FastSLAM的升级版本
      Optimal RBPF(10)           Gmapping的基础进一步优化
		
		Graph-based
	  Karto-SLAM(10)             有个开源的基于优化的2D激光SLAM，很经典
	  Cartographer(16)           与Karto-SLAM原理类似，但是更加完整

	数据的预处理--非常重要
		轮式里程计的标定
		激光雷达运动畸变去除
		不同系统之间的时间同步

	实际环境中的问题
		1.动态问题(高速物体和低速)            5.全局定位(信息太小)
		2.环境变化              			     6.地面材质的变换(6,7,8主要影响里程计)
		3.几何结构相似环境(走廊)              7.地面凹凸不平
        4.建图的操作复杂                      8.机器人载重的改变

	2D激光SLAM的趋势与视觉融合
		视觉提供的信息
			高精度的里程信息
			信息量丰富的视觉地图

3D激光SLAM
	3D激光SLAM的输入
		IMU数据
		里程计数据
		3D激光雷达数据
	3D激光SLAM的输出
		3D点云地图
		机器人的轨迹 or PoseGraph
	3D激光SLAM的帧间匹配算法
		方法								特点
	Point-Plane-ICP                点到面的距离，类似于2D的点线
	Plane-to-Plane ICP(GICP)       面到面的距离
	NDT                            划分网格。拟合高斯分布，速度快
	NICP                           在ICP的基础上，引入法向量信息，精度高
	IMLS-ICP                       对点云进行局部曲面拟合
	Feature-based Method           提取特征点和描述符进行匹配


	数据的预处理
		轮式里程计的标定
		激光雷达运动畸变去除
		不同系统之间的时间同步
	与视觉融合
		3D激光雷达为视觉特征提供深度信息
		视觉辅助激光雷达进行运动畸变去除
		视觉辅助回环检测
		视觉提供精确里程信息

激光SLAM中的问题 
		1.退化环境(Degeneration Environment)
		2.地图的动态更新(Map Update)
		3.全局定位(Global Localization)
		4.动态环境定位(Dynamic Localization)





























































































	


































