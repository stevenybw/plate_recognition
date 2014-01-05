#pragma once

#include <opencv2/opencv.hpp>

typedef std::pair< int, int > pair_int;
typedef std::pair< double, double > pair_doub;

inline std::string next_name( const std::string& key, const std::string& ext = "png" )
{
	using namespace std;
	static map< string, int > cache;
	map< string, int >::iterator it = cache.find( key );
	if ( it == cache.end() )
	{
		cache[ key ] = 0;
		it = cache.find( key );
	}
	std::stringstream ss;
	ss << "C:\\imgs\\debug\\" << key << "_" << it->second++ << "." << ext;
	return ss.str();
}

inline void draw_point( const pair_int& pi, const cv::Mat& etal, const std::string& key = "pi" )
{
	using namespace cv;
	Mat colored_rect( etal.size(), CV_8UC3 );
	cvtColor( etal, colored_rect, CV_GRAY2RGB );
	rectangle( colored_rect, Point( pi.first - 1, pi.second - 1 ), Point( pi.first + 1, pi.second + 1 ), CV_RGB( 0, 255, 0 ) );
	imwrite( next_name( key ), colored_rect );
}

inline void draw_points( const std::vector< pair_int >& pis, const cv::Mat& etal, const std::string& key = "pts" )
{
	using namespace cv;
	Mat colored_rect( etal.size(), CV_8UC3 );
	cvtColor( etal, colored_rect, CV_GRAY2RGB );
	for ( size_t mm = 0; mm < pis.size(); ++mm )
	{
		rectangle( colored_rect, Point( pis.at( mm ).first - 1, pis.at( mm ).second - 1 ), Point( pis.at( mm ).first + 1, pis.at( mm ).second + 1 ), CV_RGB( 0, 255, 0 ) );
	}
	imwrite( next_name( key ), colored_rect );
}
