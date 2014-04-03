template <class T> class XList
{
	public:
	class XListElt
		{
			public:
			XListElt(T *val){value=val;}
			~XListElt(){delete value;}
			T *value;
			XListElt *next;
			XListElt *prev;
		};
	XList();
	XList(T *val);
	~XList();

	void BeginTrace();
	bool GoForward();
	bool GoBackward();

	void ClearXList();
	void AddFirst(T *val);
	void AddLast(T *last);
	void RemoveFirst();
	void RemoveLast();

	bool CheckEmpty();
	unsigned int Length();
	T* GetFirstValue();
	T* GetLastValue();
	T* GetCurrentValue();
	/*T* DetachCurrentValue();*/

	private:
	XListElt *first;
	XListElt *last;
	XListElt *current;
};


template <class T>
XList<T>::XList()
{
	first=0;
	last=0;
	current=0;
}
template <class T>
XList<T>::XList(T *val)
{
	first=new XListElt(val);
	first->prev=0;
	first->next=0;
	last=first;
	current=0;
}

template <class T>
XList<T>::~XList()
{
	ClearXList();
}
template <class T>
void XList<T>::BeginTrace()
{
	current=0;
}
template <class T>
bool XList<T>::GoForward()
{
	if(!first)return false;
	if(!current)
		{
		current=first;
		return true;
		}
	if(current->next)
		{
		current=current->next;
		return true;
		}
	current=0;
	return false;
}
template <class T>
bool XList<T>::GoBackward()
{
	if(!last)return false;
	if(!current)
		{
		current=last;
		return true;
		}
	if(current->prev)
		{
		current=current->prev;
		return true;
		}
	current=0;
	return false;
}
template <class T>
void XList<T>::AddFirst(T *val)
{
	XListElt *p;
	p=first;
	first=new XListElt(val);
	first->next=p;
	first->prev=0;
	if(p)p->prev=first;
		else last=first;
}
template <class T>
void XList<T>::AddLast(T *val)
{
	XListElt *p;
	p=last;
	last=new XListElt;
	last->prev=p;
	last->next=0;
	last->value=val;
	if(p)p->next=last;
		else first=last;
}
template <class T>
void XList<T>::RemoveFirst()
{
	if(first)
		{
		XListElt *p;
		p=first->next;
		if(p)p->prev=0;
		if(current==first)current=0;
		delete first;
		first=p;
		}
}
template <class T>
void XList<T>::RemoveLast()
{
	if(last)
		{
		XListElt *p;
		p=last->prev;
		if(p)p->next=0;
		if(current==last)current=0;
		delete last;
		last=p;
		}
}
template <class T>
void XList<T>::ClearXList()
{
	while(first)
		{
			current=first->next;
			delete first;
			first=current;
		}
	current=0;first=0;last=0;
}

template <class T>
bool XList<T>::CheckEmpty()
{
	return first!=0;
}
template <class T>
unsigned int XList<T>::Length()
{
	if(first)
		{
		unsigned int L=1;
		XListElt *p;
		for(p=first;p->next;p=p->next)++L;
		return L;
		}
	return 0;
}
template <class T>
T* XList<T>::GetFirstValue()
{
	return first->value;
}
template <class T>
T* XList<T>::GetLastValue()
{
	return last->value;
}
template <class T>
T* XList<T>::GetCurrentValue()
{
	return current->value;
}
/*template <class T>
T* XList<T>::DetachCurrentValue()
{
	T *val=current->value;
	current->value=0;
	if (current->next)current->next->prev=current->prev;
		else last=current->prev;
	if (current->prev)current->prev->next=current->next;
		else first=current->next;
	delete current;
	current=0;
	return val;
}*/