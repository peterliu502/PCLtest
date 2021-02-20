# PCL学习记录  


--------
pcl学习笔记，`data`文件夹中的资源因为体积的原因都进行了压缩，使用前进行解压。
## I/O  
pcl不支持`laz`或者是`las`格式的文件，需要提前转换为其他格式的文件。此处主要讨论`ply`(编辑方便，文本编辑器即可)
和`pcd`（pcl支持最好）。  

1. input  
    1. pcd  
        * 特点  
          * `pcl`支持最好的格式，打开速度极快。  
          * 对于用`CloudCompare`转出的`pcd`格式，可能需要强制类型转换才能正常显示，尤其是`RGBI`都需要转成`float`  
        * 相关内容  
        ![avatar](https://img.shields.io/badge/head%20file-pcl/io/pcd__io.h-red)  
        ![avatar](https://img.shields.io/badge/function-pcl::io::loadPCDFile<T>-yellow)  
        * sample code  
        ```c++ 
        #include <iostream>
        #include <pcl/io/pcd_io.h>
    
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_pcd (new pcl::PointCloud<pcl::PointXYZRGB>);
    
        if (pcl::io::loadPCDFile<pcl::PointXYZRGB> ("../data/filtered_1704_8935 - Cloud.pcd", *cloud_pcd) == -1)
        {
            PCL_ERROR ("Couldn't read the file\n");
            return -1;
        }
        std::cout << "Loaded "
                  << cloud_pcd->width * cloud_pcd->height
                  << " data points from the file with the following fields: "
                  << std::endl;
        for (int i = 0; i < 5; ++i){
            auto point = cloud_pcd->points[i];
            std::cout << "    " << point.x
                      << " "    << point.y
                      << " "    << point.z
                      << " "    << float(point.a)
                      << " "    << float(point.r)
                      << " "    << float(point.g)
                      << " "    << float(point.b)
                      << " "    << point.rgb
                      << " "    << point.rgba
                      <<std::endl;
        }
        ```
    2. ply  
        * 特点
            * 编辑十分的方便，普通文本编辑器即可  
            * 对于用`CloudCompare`转出的`ply`格式，可能需要手动修改属性的类型与名称:  
                * `xyz`需要修改为`float`类型，`CloudCompare`转出默认是`double`  
                * `RGB`需要修改为`int`类型，`CloudCompare`转出默认是`uchar`  
                * 其他属性值需要注意名称是否正确，无前缀（`CloudCompare`可能会加上`scalar_`）
                  且首字母小写  
         * 相关内容  
          ![avatar](https://img.shields.io/badge/head%20file-pcl/io/ply__io.h-red)  
          ![avatar](https://img.shields.io/badge/function-pcl::io::loadPLYFile<T>-yellow)
        * sample code
        ```c++ 
        #include <iostream>
        #include <pcl/io/ply_io.h>
    
        pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_I (new pcl::PointCloud<pcl::PointXYZI>);
    
        if (pcl::io::loadPLYFile<pcl::PointXYZI> ("../data/filtered_1704_8935 - Cloud.ply", *cloud_I) == -1)
        {
            PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
            return (-1);
        }
    
        std::cout << "Loaded "
                  << cloud_I->width * cloud_I->height
                  << " data points from the file with the following fields: "
                  << std::endl;
    
        for (int i = 0; i < 5; ++i){
            auto point = cloud_I->points[i];
            std::cout << "    " << point.x
                      << " "    << point.y
                      << " "    << point.z
                      << " "    << point.intensity
                      <<std::endl;
        }
        ```
2. output  
