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




































