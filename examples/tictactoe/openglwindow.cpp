#include <fmt/core.h>

#include "openglwindow.hpp"

#include <imgui.h>

void OpenGLWindow::initializeGL() {
  auto windowSettings{getWindowSettings()};
  fmt::print("Initial window size: {}x{}\n", windowSettings.width, windowSettings.height);
}

void OpenGLWindow::paintGL() {
  glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]);
  glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWindow::paintUI() {

  ImGui::ShowDemoWindow();
  
  // Custom ImGui widgets
  {
    // Window begin
    ImGui::SetNextWindowContentSize(ImVec2(310.0f, 350.0f));
    ImGui::Begin("Tic-Tac-Toe");

    static char *moves[3][3] = {};

    // Static text
    auto windowSettings{getWindowSettings()};
    ImGui::Text("Game");

    ImGui::Columns(3);
    ImGui::Button(moves[0][0], ImVec2(100,100));
  
    ImGui::NextColumn();
    ImGui::Button(moves[0][1], ImVec2(100,100));
    
    ImGui::NextColumn();
    ImGui::Button(moves[0][2], ImVec2(100,100));

    ImGui::Separator();

    ImGui::NextColumn();
    ImGui::Button(moves[1][0], ImVec2(100,100));
  
    ImGui::NextColumn();
    ImGui::Button(moves[1][1], ImVec2(100,100));
    
    ImGui::NextColumn();
    ImGui::Button(moves[1][2], ImVec2(100,100));

    ImGui::Separator();

    ImGui::NextColumn();
    ImGui::Button(moves[2][0], ImVec2(100,100));
  
    ImGui::NextColumn();
    ImGui::Button(moves[2][1], ImVec2(100,100));
    
    ImGui::NextColumn();
    ImGui::Button(moves[2][2], ImVec2(100,100));

    // Window end
    ImGui::End();
  }
}