/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEAGGREGATEMAX_h
#define _REACTIVEAGGREGATEMAX_h

template <typename T>
class AggregateMax : public Operator<T, T>
{
public:
	AggregateMax();

	void OnNext(T value);

private:
	bool _any = false;
	T _max = T();
};

template <typename T>
AggregateMax<T>::AggregateMax()
{
}

template <typename T>
void AggregateMax<T>::OnNext(T value)
{
	if (!this->_any) this->_max = value;
	else this->_max = value > this->_max ? value : this->_max;
	this->_any = true;

	this->_childObserver->OnNext(this->_max);

}

#endif