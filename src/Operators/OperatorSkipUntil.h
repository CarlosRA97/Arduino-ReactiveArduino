/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEOPERATORSKIPUNTIL_h
#define _REACTIVEOPERATORSKIPUNTIL_h

template <typename T>
class OperatorSkipUntil : public Operator<T, T>
{
public:
	ReactivePredicate<T> _condition;

	OperatorSkipUntil(ReactivePredicate<T> condition);

	void OnNext(T value);

private:
	bool _started = false;
};

template <typename T>
OperatorSkipUntil<T>::OperatorSkipUntil(ReactivePredicate<T> condition)
{
	this->_condition = condition;
}

template <typename T>
void OperatorSkipUntil<T>::OnNext(T value)
{
	if (!_started && this->_condition(value))
		_started = true;

	if (_started == true)
		if (this->_childObserver != nullptr) this->_childObserver->OnNext(value);
}

#endif