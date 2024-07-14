#include <iostream>
#include <string>
#include <sqlite3.h>
#include <map>
#include <vector>

std::string workoutDescription = "Perform three sets of the exercise. In the first set, complete 12 repetitions. In the second set, complete 10 repetitions. In the third set, complete 8 repetitions.";

std::map<std::string, std::string> work_desc = {
    {"Chest", "To perform a chest press, lie on a bench with your feet flat on the floor, grip the barbell with hands slightly wider than shoulder-width apart, lower the bar to your chest, then press it back up until your arms are fully extended"},
    {"Back", "To perform a lat pulldown, sit at the lat pulldown machine and grip the bar with your hands wider than shoulder-width apart. Pull the bar down towards your chest while keeping your back straight and elbows pointed down. Slowly return the bar to the starting position with controlled movement."},
    {"Biceps", "To perform a barbell curl, stand with your feet shoulder-width apart and hold a barbell with an underhand grip (palms facing up), hands shoulder-width apart. Keep your elbows close to your torso, and curl the barbell up towards your shoulders by bending your elbows. Lower the barbell back to the starting position in a controlled manner."},
    {"Triceps", "To perform a triceps pulley pushdown, stand facing a cable machine with a high pulley attachment. Grip the bar or rope with an overhand grip, keeping your elbows close to your sides. Push the bar or rope down until your arms are fully extended, then slowly return to the starting position with control. Keep your upper arms stationary throughout the movement."},
    {"Shoulder", "To perform a military press, stand with your feet shoulder-width apart and hold a barbell at shoulder height with an overhand grip, hands slightly wider than shoulder-width apart. Press the barbell straight up overhead until your arms are fully extended, then slowly lower it back to the starting position. Keep your core engaged and avoid arching your back."},
    {"Legs", "To do a squat, stand with your feet slightly greater than shoulder-width apart and your toes pointing ahead. Slowly descend, bending through the hips, knees and ankles. Stop when your knees reach a 90-degree angle."}};

std::map<std::string, std::vector<std::string>> workouts = {
    {"Chest", {"Bench Press"}},
    {"Back", {"Lat Pulldown", "Rowing"}},
    {"Biceps", {"Barbell Curl", "Dumbbell Curl"}},
    {"Triceps", {"Pulley Pushdown", "Skull Crusher"}},
    {"Shoulder", {"Military Press", "Shrugs"}},
    {"Legs", {"Squat", "Leg Press"}}};

class Exercise
{
public:
    std::string name;
    std::string description;
    std::string musclesWorked;
    std::string equipment;

    Exercise(const std::string &name, const std::string &description, const std::string &musclesWorked, const std::string &equipment)
        : name(name), description(description), musclesWorked(musclesWorked), equipment(equipment) {}

    void display() const
    {
        std::cout << "Exercise: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Muscles Worked: " << musclesWorked << std::endl;
        std::cout << "Equipment: " << equipment << std::endl;
    }
};

class WorkoutPlanner
{
public:
    std::string bodyType;
    std::string username;

    void showCharacteristics()
    {
        if (bodyType == "ectomorph")
        {
            std::cout << "The Ectomorph Body Type" << std::endl;
            std::cout << "Characteristics:\n";
            std::cout << " - Thin and lean with a narrow frame\n";
            std::cout << " - Slender waist, narrow hips, and long limbs\n";
            std::cout << " - High endurance levels and fast metabolism\n";
        }
        else if (bodyType == "endomorph")
        {
            std::cout << "The Endomorph Body Type" << std::endl;
            std::cout << "Characteristics:\n";
            std::cout << " - Larger-boned with pear or hour-glass shape\n";
            std::cout << " - Small waist, narrow shoulders, and shorter limbs\n";
            std::cout << " - Tendency to gain weight easily with a slower metabolism\n";
        }
        else if (bodyType == "mesomorph")
        {
            std::cout << "The Mesomorph Body Type" << std::endl;
            std::cout << "Characteristics:\n";
            std::cout << " - Athletic, solid, and strong with a medium bone structure\n";
            std::cout << " - Broad shoulders and a relatively narrow waist\n";
            std::cout << " - Efficient metabolism for weight management\n";
        }
        else
        {
            std::cout << "Unknown body type.\n";
        }
    }

    void recommendNutrition()
    {
        if (bodyType == "ectomorph")
        {
            std::cout << "Nutrition advice for Ectomorph:\n";
            std::cout << " - Focus on high-calorie, nutrient-dense foods\n";
            std::cout << " - Include complex carbohydrates, lean proteins, and healthy fats\n";
        }
        else if (bodyType == "endomorph")
        {
            std::cout << "Nutrition advice for Endomorph:\n";
            std::cout << " - Focus on portion control and balanced meals\n";
            std::cout << " - Limit refined sugars and carbohydrates\n";
        }
        else if (bodyType == "mesomorph")
        {
            std::cout << "Nutrition advice for Mesomorph:\n";
            std::cout << " - Balanced diet with moderate carbohydrates, proteins, and fats\n";
            std::cout << " - Emphasize lean proteins and whole grains\n";
        }
        else
        {
            std::cout << "Unknown body type.\n";
        }
    }

    void recommendWorkout()
    {
        if (bodyType == "ectomorph")
        {
            std::cout << "Best Workouts for Ectomorphs:\n";
            std::cout << " - Endurance sports like distance running or cycling\n";
            std::cout << " - Cross-country skiing, marathons, or triathlons\n";
            std::cout << " - Circuit training and body sculpting\n";
            std::cout << "Note: Perform isolated movement + increase weight on each sets.\n";
            int i = 1;
            for (const auto &pair : workouts)
            {
                std::cout << "\n"
                          << i << ") " << pair.first << "\n";
                for (const auto &exercise : pair.second)
                {
                    std::cout << "- " << exercise << ": " << workoutDescription << "\n";
                }
                i++;
                std::cout << "\n";
            }
        }
        else if (bodyType == "endomorph")
        {
            std::cout << "Best Workouts for Endomorphs:\n";
            std::cout << " - Cardio exercises like running, swimming, and cycling\n";
            std::cout << " - Powerlifting and high-intensity circuit training\n";
            std::cout << " - Incorporate plyometrics and bodyweight exercises\n";
            std::cout << "Note: Perform isolated movement on each sets.\n";
            int i = 1;
            for (const auto &pair : workouts)
            {
                std::cout << "\n"
                          << i << ") " << pair.first << "\n";
                std::cout << "- " << work_desc[pair.first] << "\n";
                for (const auto &exercise : pair.second)
                {
                    std::cout << "- " << exercise << ": " << workoutDescription << "\n";
                }
                i++;
                std::cout << "\n";
            }
        }
        else if (bodyType == "mesomorph")
        {
            std::cout << "Best Workouts for Mesomorphs:\n";
            std::cout << " - Strength training with weights and high-intensity workouts\n";
            std::cout << " - Interval training and power-based sports\n";
            std::cout << " - Alternating steady-state cardio with HIIT\n";
            int i = 1;
            for (const auto &pair : workouts)
            {
                std::cout << "\n"
                          << i << ") " << pair.first << "\n";
                for (const auto &exercise : pair.second)
                {
                    std::cout << "- " << exercise << ": " << workoutDescription << "\n";
                }
                i++;
                std::cout << "\n";
            }
        }
        else
        {
            std::cout << "Unknown body type.\n";
        }
    }

    void showExercise(const std::string &exerciseName)
    {
        Exercise exercise("", "", "", "");
        if (exerciseName == "Lat Pulldown")
        {
            exercise = Exercise(
                "Lat Pulldown",
                "Sit at a lat pulldown machine and grasp the bar with a wide overhand grip. Pull the bar down to your chest, squeezing your shoulder blades together. Slowly return to the starting position.",
                "Latissimus Dorsi, Biceps, Shoulders",
                "Lat Pulldown Machine");
        }
        else if (exerciseName == "Rowing")
        {
            exercise = Exercise(
                "Rowing",
                "Sit on the rowing machine, grasp the handle, and push with your legs while pulling the handle towards your chest. Extend your legs and arms fully before repeating.",
                "Back, Shoulders, Arms, Legs",
                "Rowing Machine");
        }
        else if (exerciseName == "Bench Press")
        {
            exercise = Exercise(
                "Bench Press",
                "Lie on a flat bench with your feet on the ground. Hold the barbell with an overhand grip, slightly wider than shoulder-width. Lower the bar to your chest and then press it back up to the starting position.",
                "Chest, Shoulders, Triceps",
                "Barbell, Bench");
        }
        else if (exerciseName == "Barbell Curl")
        {
            exercise = Exercise(
                "Barbell Curl",
                "Stand up straight while holding a barbell with a shoulder-width grip. Curl the barbell up towards your shoulders, then slowly lower it back down.",
                "Biceps",
                "Barbell");
        }
        else if (exerciseName == "Dumbbell Curl")
        {
            exercise = Exercise(
                "Dumbbell Curl",
                "Stand up straight with a dumbbell in each hand at arm's length. Curl the weights while contracting your biceps, then slowly lower them back to the starting position.",
                "Biceps",
                "Dumbbells");
        }
        else if (exerciseName == "Pulley Pushdown")
        {
            exercise = Exercise(
                "Pulley Pushdown",
                "Stand facing a high pulley with a bar attachment. Grab the bar with an overhand grip and push it down until your arms are fully extended, then slowly return to the starting position.",
                "Triceps",
                "Cable Machine");
        }
        else if (exerciseName == "Skull Crusher")
        {
            exercise = Exercise(
                "Skull Crusher",
                "Lie on a flat bench holding an EZ curl bar with a close grip. Extend your arms fully, then lower the bar towards your forehead by bending your elbows, and then extend your arms back to the starting position.",
                "Triceps",
                "EZ Curl Bar, Bench");
        }
        else if (exerciseName == "Military Press")
        {
            exercise = Exercise(
                "Military Press",
                "Stand with your feet shoulder-width apart and hold a barbell at shoulder height with an overhand grip. Press the barbell overhead until your arms are fully extended, then lower it back to the starting position.",
                "Shoulders, Triceps",
                "Barbell");
        }
        else if (exerciseName == "Shrugs")
        {
            exercise = Exercise(
                "Shrugs",
                "Stand up straight holding a dumbbell in each hand at your sides. Raise your shoulders as high as possible, then lower them back to the starting position.",
                "Trapezius",
                "Dumbbells");
        }
        else if (exerciseName == "Squat")
        {
            exercise = Exercise(
                "Squat",
                "Stand with your feet shoulder-width apart and hold a barbell across your upper back. Lower your body by bending your knees and hips, then return to the starting position.",
                "Quadriceps, Hamstrings, Glutes",
                "Barbell");
        }
        else if (exerciseName == "Leg Press")
        {
            exercise = Exercise(
                "Leg Press",
                "Sit on a leg press machine with your feet shoulder-width apart on the platform. Push the platform away by extending your legs, then slowly return to the starting position.",
                "Quadriceps, Hamstrings, Glutes",
                "Leg Press Machine");
        }
        else
        {
            std::cout << "Exercise not found.\n";
            return;
        }
        exercise.display();
    }

    void saveToDatabase(sqlite3 *db)
    {
        std::string sql = "INSERT INTO workout_plans (username, body_type, recommendations) VALUES ('" + username + "', '" + bodyType + "', 'Recommended workout plan for " + bodyType + "');";
        char *errMsg = 0;
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);

        if (rc != SQLITE_OK)
        {
            std::cerr << "SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
};

void planWorkout(const std::string &username)
{
    WorkoutPlanner planner;
    planner.username = username;

    std::cout << "Enter your body type (ectomorph/endomorph/mesomorph): ";
    std::cin >> planner.bodyType;

    int choice;
    while (true)
    {
        std::cout << "1. Characteristics\n2. Nutrition and Diet Advice\n3. Exercise\n4. Show Exercise\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1)
        {
            planner.showCharacteristics();
        }
        else if (choice == 2)
        {
            planner.recommendNutrition();
        }
        else if (choice == 3)
        {
            planner.recommendWorkout();
        }
        else if (choice == 4)
        {
            std::cout << "Enter exercise name (e.g., 'Lat Pulldown'): ";
            std::string exerciseName;
            std::cin.ignore(); // To clear the newline character left by std::cin
            std::getline(std::cin, exerciseName);
            planner.showExercise(exerciseName);
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "Do you want to continue? (yes/no): ";
        std::string cont;
        std::cin >> cont;
        if (cont == "no")
            break;
    }

    sqlite3 *db;
    int rc = sqlite3_open("fitness.db", &db);
    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    planner.saveToDatabase(db);
    sqlite3_close(db);
}

int main()
{
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

    planWorkout(username);

    return 0;
}
