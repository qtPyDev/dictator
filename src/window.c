#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "proj_export.h"

char title[20] = "dictator v0.1.0 beta";



int test_proj_export() {
    struct scene scn;

    scn.chapter = 1;
    scn.episode = 2;
    strcpy(scn.type, "dialogue");
    strcpy(scn.text, "this is a sentence !");

    export_to_json(scn);

    return 0;
}


int main() {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(1280, 720, title, NULL, NULL);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    test_proj_export();

    return 0;
}
