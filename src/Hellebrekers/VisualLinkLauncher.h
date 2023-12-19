//
// Created by Kasper de Bruin on 15/12/2023.
//

#pragma once
#include <Terminal/TerminalWindow.h>
#include <UIWindows/UIWindow.h>
#include <Utils/Utils.h>
#include <Application.h>

namespace HummingBirdKasper::VisualLink {

struct Client {
public:
  Client(std::string name, std::string location, std::vector<HummingBirdCore::Terminal::Command> commands)
      : name(name), location(location), commands(commands) {}

  ~Client() = default;

  std::string getName() const { return name; }
  std::string getLocation() const { return location; }

  std::vector<HummingBirdCore::Folder> getFolders() const {
//    std::vector<HummingBirdCore::Folder> folders =
//        HummingBirdCore::FileUtils::getFoldersInLocation(location);
    return std::vector<HummingBirdCore::Folder>{};
  }

  std::vector<HummingBirdCore::Terminal::Command> getCommands() const {
    return commands;
  }

  std::vector<HummingBirdCore::Terminal::Command> getRunningCommands() const { return runningCommands; }

  void executeCommand(int index) {
//    commands[index].executeCommand();
    runningCommands.push_back(commands[index]);
  }

private:
  const std::string name;
  const std::string location;

  std::vector<HummingBirdCore::Terminal::Command> commands;
  std::vector<HummingBirdCore::Terminal::Command> runningCommands;
};

class VisualLinkLauncher : public HummingBirdCore::UIWindow {
public:
  VisualLinkLauncher() : VisualLinkLauncher(ImGuiWindowFlags_None) {}
  // todo: remove hardcoded nu geen schik doei
  VisualLinkLauncher(const ImGuiWindowFlags flags)
      : UIWindow(flags, "Visual link Launcher") {
//    m_clients = fetchAllClients();
//
//    m_currentFolder = HummingBirdCore::Folder(m_clients[0].getLocation());
  }

  ~VisualLinkLauncher() = default;

  void render() override;

private:
  void changeClient(int index) {
    m_selectedClientIndex = index;
//    m_currentFolder = HummingBirdCore::Folder(m_clients[index].getLocation());
  }

  std::vector<Client> fetchAllClients() {
//    std::vector<Client> clients;
//    std::vector<HummingBirdCore::Folder> folders =
//        HummingBirdCore::FileUtils::getFoldersInLocation(
//            c_defaultClientsLocation);
//
//    for (auto &folder : folders) {
//      std::string clientName = folder.getName();
//      std::string clientLocation = folder.getName();
//      std::vector<HummingBirdCore::Terminal::Command> commands;
//
//      // KeyCloak command
//      commands.emplace_back("KeyCloak Start",
//                            "./keycloak/bin/kc.sh start",
//                            clientLocation);
//
//      commands.emplace_back("Artemis Start",
//                            "./artemis/vlbroker/bin/artemis run",
//                            clientLocation);
//      commands.emplace_back("Wildfly Start",
//                            "./wildfly/bin/standalone.sh --debug",
//                            clientLocation);
//
//      clients.emplace_back(clientName, clientLocation, commands);
//    }
//
//    return clients;
  }

private:
  const std::string c_defaultClientsLocation = "/opt/";

  std::vector<Client> m_clients;
  int m_selectedClientIndex = 0;

  HummingBirdCore::Folder m_currentFolder;
};
} // namespace HummingBirdKasper::VisualLink
