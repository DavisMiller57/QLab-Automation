#include <iostream>
#include <lo/lo.h> // liblo for OSC communication

// QLab's default OSC port
#define QLAB_OSC_PORT 53000
#define QLAB_IP "localhost"

// Function to send an OSC message to QLab
void sendOSCMessage(const std::string &cmd, const std::string &arg) {
    lo_address qlab = lo_address_new(QLAB_IP, std::to_string(QLAB_OSC_PORT).c_str());
    if (!qlab) {
        std::cerr << "Failed to create OSC address." << std::endl;
        return;
    }
    
    int result = lo_send(qlab, cmd.c_str(), "s", arg.c_str());
    if (result == -1) {
        std::cerr << "Error sending OSC message." << std::endl;
    } else {
        std::cout << "Sent OSC message: " << cmd << " " << arg << std::endl;
    }
}

int main() {
    std::cout << "Starting Event Handler..." << std::endl;
    
    // Example: Trigger QLab cue number 1
    sendOSCMessage("/cue/1/start", "");
    
    // Example: Trigger a specific Eos cue (QLab handles the forwarding)
    sendOSCMessage("/cue/2/start", "");
    
    // Example: Activate mixer settings (handled through QLab)
    sendOSCMessage("/cue/3/start", "");
    
    return 0;
}
