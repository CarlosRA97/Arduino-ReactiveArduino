/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEOBSERVERDONOTHING_h
#define _REACTIVEOBSERVERDONOTHING_h

template <typename T>
class ObserverDoNothing : public IObserver<T>
{
public:
	ObserverDoNothing();

	void OnNext(T value);
	void OnComplete();

private:
	ReactiveAction<T> _doAction;
};

template <typename T>
inline ObserverDoNothing<T>::ObserverDoNothing()
{
}

template <typename T>
inline void ObserverDoNothing<T>::OnNext(T value)
{
}

template <typename T>
inline void ObserverDoNothing<T>::OnComplete()
{
}

#endif