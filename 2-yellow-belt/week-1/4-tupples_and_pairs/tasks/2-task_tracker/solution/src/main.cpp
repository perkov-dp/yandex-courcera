#include <iostream>
#include <map>
using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
	  return person_tasks_info.at(person);
  };

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
	  person_tasks_info[person][TaskStatus::NEW]++;
  };

  // Обновить статусы по заданному количеству задач конкретного разработчика
  // Метод PerformPersonTasks должен реализовывать следующий алгоритм:
  // 3) Рассмотрим первые task_count задач и переведём каждую из них в следующий статус в соответствии
  // с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
  // 4) Вернём кортеж из двух элементов: информацию о статусах обновившихся задач
  // (включая те, которые оказались в статусе DONE) и информацию о статусах остальных не выполненных задач.
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int upd_task_count
  ) {
	  // Примечание
	  // Обновление словаря одновременно с итерированием по нему может привести к непредсказуемым последствиям.
	  // При возникновении такой необходимости рекомендуется сначала в отдельном временном словаре собрать
	  // информацию об обновлениях, а затем применить их к основному словарю.
      TasksInfo refreshable;	//	обновившиеся задачи
      TasksInfo untouched;		//	незатронутые задачи
      TasksInfo updated;		//	итоговая конфигурация задач

      //	1) Рассмотрим все не выполненные задачи разработчика person.
	  auto tmp_task_info = person_tasks_info[person];
	  for (auto& task_info : tmp_task_info) {
		  //	если у польз-ля есть задачи
		  if (task_info.second > 0) {
			  // 2) Упорядочим их по статусам: сначала все задачи в статусе NEW,
			  // затем все задачи в статусе IN_PROGRESS и, наконец, задачи в статусе TESTING.

			  //	для задач в статусе НОВЫЕ
			  if (task_info.first == TaskStatus::NEW) {
				  int outstanding_task_kol = task_info.second;	//	невыполненные задачи в данной категории

				  // 3) Рассмотрим первые upd_task_count задач и переведём каждую из них в следующий статус
				  // в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
				  // + проверка условия задачи: Если task_count превышает текущее количество невыполненных
				  // задач разработчика, достаточно считать, что task_count равен количеству невыполненных
				  // задач: дважды обновлять статус какой-либо задачи в этом случае не нужно.
	              while (outstanding_task_kol > 0 && upd_task_count > 0) {
                      ++refreshable[TaskStatus::IN_PROGRESS];
                      ++updated[TaskStatus::IN_PROGRESS];

                      outstanding_task_kol--;
	            	  upd_task_count--;
	              }
	              //	если остались еще невыполненные задачи, то заносим их в список невыполненных
	              //	также заносим их в итоговый список задач для этого разработчика
	              if (outstanding_task_kol > 0) {
	            	  untouched[TaskStatus::NEW] += outstanding_task_kol;
	            	  updated[TaskStatus::NEW] += outstanding_task_kol;
	              }
			  }
			  //	для задач в статусе В РАЗРАБОТКЕ
			  else if (task_info.first == TaskStatus::IN_PROGRESS) {
				  int outstanding_task_kol = task_info.second;	//	невыполненные задачи в данной категории

				  // 3) Рассмотрим первые upd_task_count задач и переведём каждую из них в следующий статус
				  // в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
				  // + проверка условия задачи: Если task_count превышает текущее количество невыполненных
				  // задач разработчика, достаточно считать, что task_count равен количеству невыполненных
				  // задач: дважды обновлять статус какой-либо задачи в этом случае не нужно.
	              while (outstanding_task_kol > 0 && upd_task_count > 0) {
                      ++refreshable[TaskStatus::TESTING];
                      ++updated[TaskStatus::TESTING];

                      outstanding_task_kol--;
	            	  upd_task_count--;
	              }
	              //	если остались еще невыполненные задачи, то заносим их в список невыполненных
	              //	также заносим их в итоговый список задач для этого разработчика
	              if (outstanding_task_kol > 0) {
	            	  untouched[TaskStatus::IN_PROGRESS] += outstanding_task_kol;
	            	  updated[TaskStatus::IN_PROGRESS] += outstanding_task_kol;
	              }
			  }
			  //	для задач в статусе ТЕСТИРУЕТСЯ
			  else if (task_info.first == TaskStatus::TESTING) {
				  int outstanding_task_kol = task_info.second;	//	невыполненные задачи в данной категории

				  // 3) Рассмотрим первые upd_task_count задач и переведём каждую из них в следующий статус
				  // в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
				  // + проверка условия задачи: Если task_count превышает текущее количество невыполненных
				  // задач разработчика, достаточно считать, что task_count равен количеству невыполненных
				  // задач: дважды обновлять статус какой-либо задачи в этом случае не нужно.
	              while (outstanding_task_kol > 0 && upd_task_count > 0) {
                      ++refreshable[TaskStatus::DONE];
                      ++updated[TaskStatus::DONE];

                      outstanding_task_kol--;
	            	  upd_task_count--;
	              }
	              //	если остались еще невыполненные задачи, то заносим их в список невыполненных
	              //	также заносим их в итоговый список задач для этого разработчика
	              if (outstanding_task_kol > 0) {
	            	  untouched[TaskStatus::TESTING] += outstanding_task_kol;
	            	  updated[TaskStatus::TESTING] += outstanding_task_kol;
	              }
			  }
			  //	для задач в статусе ЗАВЕРШЕНА
			  else if (task_info.first == TaskStatus::DONE) {
				  if (task_info.second > 0) {
					  updated[TaskStatus::DONE] += task_info.second;
				  }
			  }
		  }
		  else {
			  //	если у разработчика нет задач, то возвращаем пустой кортеж
			  //	make_tuple - создает кортеж из значений
			  return make_tuple(refreshable, untouched);
		  }
	  }
	  person_tasks_info[person] = updated;
      return {refreshable, untouched};
  };

private:
  //	список задач для каждого разработчика
  map <string, TasksInfo> person_tasks_info;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
