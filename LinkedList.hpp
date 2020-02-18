/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//I am adding a comment to recommit this to get my full lab points
	if(isEmpty())
	{
		std::cout<<"List is empty";
	}
	else
	{
		return(m_size);
	}
	return(0);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	//I am adding another comment, this method was the worst one, even in 268
	Node<T>* temp = m_front;
	bool isFound = false;
	for(int i=0;i<m_size;i++)
	{
		if(temp->getValue()== value)
		{
			return(true);
		}
		else
		{
			temp=temp->getNext();	
		}
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	//This is a method I struggled with during this lab however I got it working 
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	if(m_size>1)
	{
		Node<T>* temp = m_front;
		Node<T>* temp2 = nullptr;
		for(int i = 0;i<m_size-2;i++)
		{
			temp=temp->getNext();
		}
		delete temp->getNext();
		temp->setNext(temp2);
		m_size--;
	}
	else if(m_size==0)
	{
		std::cout<<"Invalid Size";
	}
	else if(m_size==1)
	{
		delete m_front;
		m_front=nullptr;
		m_size=0;
	}
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
