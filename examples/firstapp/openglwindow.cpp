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
  // Show FPS meter and fullscreen button using parent class
  abcg::OpenGLWindow::paintUI();

  // Custom ImGui widgets
  {
    // Window begin
    ImGui::Begin("Hello, First App!");

    // Static text
    auto windowSettings{getWindowSettings()};
    ImGui::Text("Current window size: %dx%d (in windowed mode)", windowSettings.width, windowSettings.height);

    // Slider from 0.0f to 1.0f
    static float f{};
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

    // ColorEdit to change the clear color
    ImGui::ColorEdit3("clear color", m_clearColor.data());

    // Buttons
    if(ImGui::Button("Click here", ImVec2(100,50))){
      fmt::print("Button pressed.\n");
    }

    ImGui::Button("Another button", ImVec2(-1, 50));

    // How does ImGui know the "Another Button" was clicked?
    if(ImGui::IsItemClicked()) {
      fmt::print("Another button pressed.\n");
    }

    // Check box
    static bool enabled{true};
    ImGui::Checkbox("Some option", &enabled);
    // fmt::print("The checkbox is {}\n", enabled ? "enabled" : "disabled");

    // Combo box
    static std::size_t currentIndex{};
    std::vector<std::string> comboItems{"AAA", "BBB", "CCC"};

    if (ImGui::BeginCombo("Combo box", comboItems.at(currentIndex).c_str())) {
      for (auto index{0u}; index < comboItems.size(); ++index) {
        const bool isSelected{currentIndex == index};
        if (ImGui::Selectable(comboItems.at(index).c_str(), isSelected))
          currentIndex = index;

        // Set the initial focus when opening the combo (scrolling + keyboard
        // navigation focus)
        if (isSelected) ImGui::SetItemDefaultFocus();
      }
      ImGui::EndCombo();
    }

    // fmt::print("Selected combo box item: {}\n", comboItems.at(currentIndex));

    // More static text
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0 / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    // Window end
    ImGui::End();
  }
}