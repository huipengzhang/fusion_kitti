


#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>


using namespace std;





int main(int argc, const char *argv[])
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB> ());
    pcl::PCDReader reader;
    std::stringstream ss;
    ss.str("");
    ss<<argv[1];
    reader.read (ss.str(), *cloud);





    pcl::visualization::PCLVisualizer viewer("Cloud viewer");
    //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    viewer.setCameraPosition(0,0,-3.0,0,-1,0);
    viewer.addCoordinateSystem(0.3);
    //viewer = customColourVis(cloud);


    viewer.addPointCloud(cloud,"sample cloud");

    viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "sample cloud");
    viewer.setBackgroundColor(255,255,255);
    while(!viewer.wasStopped()){ // Display the visualiser until 'q' key is pressed
        viewer.spinOnce ();
    }




    return 0;
}

