#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 origin)
{
    this->width = width;
    this->height = height;
    this->origin = origin;
}

glm::mat4 Camera::mat(float fov, float near, float far)
{
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(origin, origin + lookat, up);

    view = glm::rotate(view, glm::radians(45.0f), up);

    projection = glm::perspective(glm::radians(fov), (float)width / height, near, far);

    return (projection * view);
}

void Camera::inputs(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    // Forward movement (W)
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        origin += cameraSpeed * lookat;
    }
    // Backward movement (S)
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        origin -= cameraSpeed * lookat;
    }
    // Left movement (A)
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        origin -= glm::normalize(glm::cross(lookat, up)) * cameraSpeed;
    }
    // Right movement (D)
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        origin += glm::normalize(glm::cross(lookat, up)) * cameraSpeed;
    }

    // Additional logic for moving up and down
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            origin += up * cameraSpeed; // Move Up
        }
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
            origin -= up * cameraSpeed; // Move Down
        }
    }

}