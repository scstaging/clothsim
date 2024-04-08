#include <Eigen/Core>

class VecUtils {

	Eigen::Matrix4f rotate(Eigen::Matrix4f mat, float angle, Eigen::Vector3f axis);
	Eigen::Matrix4f translate(Eigen::Matrix4f mat, Eigen::Vector3f translationVector);
	Eigen::Matrix4f perspective(float fov, float aspectRatio, float near, float far);

};