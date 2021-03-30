#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode;
class ChatLogic;

class ChatBot
{
private:
    wxBitmap *_image; // avatar image
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;
    int ComputeLevenshteinDistance(std::string s1, std::string s2);
	void print(std::string title);
public:

    ChatBot ();                                    // constructor WITHOUT memory allocation
    ChatBot (std::string filename);                // constructor WITH memory allocation
    ChatBot (const ChatBot& other);                // copy constructor
    ChatBot (ChatBot&& other) noexcept;            // move constructor
    ChatBot& operator= (const ChatBot& other);     // copy assignment
    ChatBot& operator= (ChatBot&& other) noexcept; // move assignment
    ~ChatBot ();

    void SetCurrentNode (GraphNode *node);
    void SetRootNode (GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle (ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle () { return _image; }
    void ReceiveMessageFromUser (std::string message);
};

#endif /* CHATBOT_H_ */