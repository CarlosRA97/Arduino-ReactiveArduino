/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEOPERATORLOOP_h
#define _REACTIVEOPERATORLOOP_h

template <typename T>
class OperatorLoop : public Operator<T, T>
{
public:
	OperatorLoop();

	void OnNext(T value);
	void OnComplete();

private:
	int _last = false;
	bool _any = false;
};

template <typename T>
OperatorLoop<T>::OperatorLoop()
{
}

template <typename T>
void OperatorLoop<T>::OnNext(T value)
{
	if (this->_childObserver != nullptr) this->_childObserver->OnNext(value);
}

template <typename T>
void OperatorLoop<T>::OnComplete()
{
	if (this->_parentObservable != nullptr) this->_parentObservable->Reset();
}

#endif