pipeline {
agent any
stages {
        stage('Build') {
            steps {
                echo 'Building..'
				sh '''
						set +x
						cd c_programs
						echo -e "\n\n**************************** This is a Build JOB **************************** "

						if [[ -x "ABC.exe" ]]; then
							echo "STEP 1:	Cleaning existing builds ........"
								ls *.exe | nl | sed 's/	/) /g' | tr '\n' ' ' 
									rm -f "./ABC.exe" 
							echo -e "\n\nSTEP 2:	Cleaning existing Object files........"
								ls *.o | nl | sed 's/	/) /g' | tr '\n' ' '
									rm -f *.o
						fi   
							echo -e "\n\nSTEP 3:	Initiating Build for below files (using make)........"
								ls *.c | nl | sed 's/	/) /g' | tr '\n' ' '
							echo -e "\n"    
								make

						#dt=$(date +%Y-%m-%d_%H:%M:%S)

						if [[ -x "./ABC.exe" ]]; then  
							echo -e "\nSTEP 4:	Build Successful"
							echo "       	BUILD_FILE: $(pwd)/ABC.exe"	
						else
							echo -e "**************** ERROR *********************\n"
							echo "Build failure - No executable file generated"
							echo -e "********************************************\n"
							exit 1
						fi    

						echo -e "\n************************************************************************** "
				'''
				
            }
        }
        stage('deploy') {
            steps {
                echo 'Deploying to TEST environment..'
				sh '''
					set +x
					file="$(pwd)/c_programs/ABC.exe"
					[[ -f "$file" ]] && sudo rm -f "$file"
					pwd; sudo chmod 777 build; ./build 1> /dev/null
					
				echo -e "\n\n**************************** This is a Deploy JOB $file **************************** "
				if [[ -f "$file" ]]; then 
				echo -e "\nSTEP 1: Deploying $file with default input........"
				$file -v -i <<<"5 400 500 600"

				if [ $? -eq 0 ]; then
				  if [[ -x "$file" ]]; then  
					  echo -e "\nSTEP 2:	Deployment Successful - Build pushed to artifactory"
					  echo "       	ARTIFACTORY_PATH: /home/ec2-user/builds/$file"
				  fi
				else  
					  echo -e "**************** ERROR *********************\n"
					  echo "Deployment failure - ABC.exe cannot be executed "
					  echo -e "********************************************\n"
					  exit 1
				fi
				else 
					 echo -e "**************** ERROR *********************\n"
					  echo "Build - ABC.exe notfound $file "
					  echo -e "********************************************\n"
					  exit 1
				fi
				'''
            }
        }
        stage('test') {
            steps {
                echo 'Testing....'
				sh '''
				set +x
					file="$(pwd)/c_programs/ABC.exe"
					[[ -f "$file" ]] && sudo rm -f "$file"
					pwd; sudo chmod 777 build; ./build 1> /dev/null
					
				echo -e "\n\n**************************** This is a Deploy JOB for $file**************************** "
				if [[ -f "$file" ]]; then 
				count=1
				
				for i in {1..10}
				do
					oe=$((1000 + RANDOM % 10000))
					fact=$((1 + RANDOM % 15))
					num1=$((1 + RANDOM % 100))
					num2=$((1 + RANDOM % 1000))
					
						echo -e "\n-------------------------- TEST_CASE ($count) --------------------------"
						$file -v -i <<<"$fact $oe $num1 $num2"
					
					if [ $? -eq 0 ]; then
						echo -e "\n      RESULT -> TEST_CASE (${count}): SUCCESS" 
					else  
						echo -e "\n      RESULT -> TEST_CASE (${count}): FAILED"
						exit 1
					fi

					echo "-------------------------------------------------------------------"
					((count++))
				done
				else 
					 echo -e "**************** ERROR *********************\n"
					  echo "Build - ABC.exe notfound $file "
					  echo -e "********************************************\n"
					  exit 1
				fi
				'''
					}
				}
    }
}
