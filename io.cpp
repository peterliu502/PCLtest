#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main() {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_RGB (new pcl::PointCloud<pcl::PointXYZRGB>);

    if (pcl::io::loadPCDFile<pcl::PointXYZRGB> ("../data/filtered_1704_8935 - Cloud.pcd", *cloud_RGB) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read the file\n");
        return -1;
    }
    std::cout << "Loaded "
              << cloud_RGB->width * cloud_RGB->height
              << " data points from the file with the following fields: "
              << std::endl;
    for (int i = 0; i < 5; ++i){
        auto point = cloud_RGB->points[i];
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

    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_I (new pcl::PointCloud<pcl::PointXYZI>);

    if (pcl::io::loadPLYFile<pcl::PointXYZI> ("../data/filtered_1704_8935 - Cloud.ply", *cloud_I) == -1) //* load the file
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

    return 0;
}
