/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEOPERATORTIMEOUTMILLIS_h
#define _REACTIVEOPERATORTIMEOUTMILLIS_h

template <typename T>
class OperatorTimeoutMillis : public Operator<T, T>
{
public:
	OperatorTimeoutMillis(unsigned long interval, ReactiveAction<T> action);

	void OnNext(T value);
	void OnComplete();
	void Update();

private:
	ReactiveAction<T> _doAction;
	unsigned long _starTime;
	unsigned long _interval;
	bool _completed = false;
};

template <typename T>
OperatorTimeoutMillis<T>::OperatorTimeoutMillis(unsigned long interval, ReactiveAction<T> action)
{
	this->_doAction = action;
	this->_interval = interval;
	this->_starTime = millis();
}

template <typename T>
void OperatorTimeoutMillis<T>::OnNext(T value)
{
	this->_doAction(value);
	this->_starTime = millis();

	if (this->_childObserver != nullptr) this->_childObserver->OnNext(value);
}

template <typename T>
inline void OperatorTimeoutMillis<T>::OnComplete()
{
	this->_completed = true;
	if (this->_childObserver != nullptr) this->_childObserver->OnComplete();
}

template <typename T>
inline void OperatorTimeoutMillis<T>::Update()
{
	if (this->_completed) return;

	if (millis() - this->_starTime > this->_interval)
	{
		if (this->_doAction != nullptr) this->_doAction();
		this->_completed = true;
		if (this->_childObserver != nullptr) this->_childObserver->OnComplete();
	}
}

#endif