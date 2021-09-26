#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    std::cout<<"Creating GraphNode at "<<this<<" with id "<<id<<"\n"; 
    _id = id;
}

GraphNode::~GraphNode()
{
    std::cout<<"Deleting GraphNode at "<<this<<" with id "<<this->GetID()<<"\n";
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(std::weak_ptr<GraphEdge> edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::shared_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge);
}

void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    std::cout<<"Transfering Chatbot to GraphNode with id "<<this->GetID()<<" in MoveChatBotHere fn\n"; 
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
    std::cout<<"Transfered Chatbot to GraphNode with id "<<this->GetID()<<" in MoveChatBotHere fn\n"; 
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    return _childEdges[index].get();
}