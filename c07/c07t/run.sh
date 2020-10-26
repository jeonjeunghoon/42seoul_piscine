#!/bin/bash

POSITIONAL=()
SPECIFIED=""
RUN_COMPILE=1
RUN_NORMINETTE=1

echo $SPECIFIED
while [[ $# -gt 0 ]]; do
	key="$1"

	case $key in
	--no-color)
		NO_COLOR="1"
		shift # past value
		;;
	# -1|--searchpath)
	# SPECIFIED="$2"
	# shift # past argument
	# shift # past value
	# ;;
	-n)
		RUN_COMPILE=0
		shift
		;;
	-c)
		RUN_NORMINETTE=0
		shift
		;;
	-0)
		SPECIFIED=00
		shift
		;;
	-1)
		SPECIFIED=01
		shift
		;;
	-2)
		SPECIFIED=02
		shift
		;;
	-3)
		SPECIFIED=03
		shift
		;;
	-4)
		SPECIFIED=04
		shift
		;;
	-5)
		SPECIFIED=05
		shift
		;;
	-6)
		SPECIFIED=06
		shift
		;;
	-7)
		SPECIFIED=07
		shift
		;;
	-8)
		SPECIFIED=08
		shift
		;;
	-9)
		SPECIFIED=09
		shift
		;;
	-10)
		SPECIFIED=10
		shift
		;;
	-11)
		SPECIFIED=11
		shift
		;;
	-12)
		SPECIFIED=12
		shift
		;;
	--default)
		DEFAULT=YES
		shift # past argument
		;;
	*)                  # unknown option
		POSITIONAL+=("$1") # save it in an array for later
		shift              # past argument
		;;
	esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

if [ "${NO_COLOR}" != "1" ]; then
	CYAN='\033[1;36m'
	LCYAN='\033[0;34m'
	GRAY='\033[1;30m'
	NC='\033[0m' # No Color
	PURPLE='\033[0;32m'
fi

function printline() {
	echo -e ${GRAY}'------------------------------------------------------------'${NC}
}

function printsharp() {
	echo "##"
}

function printdoubleline() {
	echo ""
	echo ""
	echo ""
	echo '============================================================'
}
function printhead() {
	printdoubleline
	echo -e ${CYAN}'##' "$1" 테스트를 시작합니다.${NC}
}
function printmsg() {
	echo ""
	echo '>>>' "$1"
}
function printcontent() {
	echo '##' 실행 명령 : "$1"
	eval $1
}

# 각종 경로 설정
im_relative=$(dirname $0)
cd $im_relative
GENERATED_PATH=$(pwd -P)
cd ..
PROJECT_PATH=$(pwd -P)
EX_FOLDERS=$(find . -type d -regex '.*ex[0-9]\{2\}')
EX_FOLDERS_ARRAY=($EX_FOLDERS)
EX_COUNT=${#EX_FOLDERS_ARRAY[@]}
PROJECT_NAME=$(pwd | sed -E 's/[\/]+(.+\/)+//')

# 생성할 소스파일 및 목적파일 폴더 생성
mkdir ${GENERATED_PATH}/src ${GENERATED_PATH}/build


if [[ "${RUN_NORMINETTE}" == "1" && -z "${SPECIFIED}" ]]; then
	find ${PROJECT_PATH} -name "ft_*.c" -print | xargs norminette -R CheckForbiddenSourceHeader | sed -E "s/(Warn|Err)(.*)(.)$/    \1\2\3/g" | sed 's/Norme:/^Norme:/' | tr '^' '\n'

elif [ "${RUN_NORMINETTE}" == "1" ]; then
	norminette -R CheckForbiddenSourceHeader "${PROJECT_PATH}/ex${SPECIFIED}" | sed -E "s/(Warn|Err)(.*)(.)$/    \1\2\3/g" | sed 's/Norme:/^Norme:/' | tr '^' '\n'
fi

for folder in "${EX_FOLDERS_ARRAY[@]}"; do

	exname=$(echo ${folder} | sed 's/\.\///')
	if [[ -z "${SPECIFIED}" || "${exname}" == "ex${SPECIFIED}" ]]; then
		source_path=${PROJECT_PATH}/${exname}
		filelist=$(ls $source_path)
		filename=$(ls -l ${source_path} | sed '1d' | awk '{print $NF}')


		funcname=$(echo $filelist | sed 's/\.c//g')
		ccount=$(echo "$filelist" | wc -w | sed 's/[[:blank:]]//g')
		if [ ${ccount} == "0" ]; then
			echo "${source_path}에 소스파일이 존재하지 않습니다."
			continue
		fi

		# 컴파일 모드가 아니라면 continue
		if [ "${RUN_COMPILE}" == "0" ]; then
			continue
		fi

		# c 파일 작성

		test_code=$(cat ${GENERATED_PATH}/testcode | sed -n -e "/^${exname}:/,/^[^ ]*:$/p" | sed -e "$ d" -e "1d")
		test_expected=$(cat ${GENERATED_PATH}/testcode | sed -n -e "/^${exname}-expected:/,/^[^ ]*:$/p" | sed -e "$ d" -e "1d")
		other_code=$(cat ${GENERATED_PATH}/testcode | sed -n -e "/^${exname}-other:/,/^[^ ]*:$/p" | sed -e "$ d" -e "1d")
		include=$(cat ${GENERATED_PATH}/testcode | sed -n -e "/^include:/,/^[^ ]*:$/p" | sed -e "$ d" -e "1d")
		source_files=$(find ${source_path} -type f | grep -E "[.]c$")
		
		all_content=$(echo "${source_files}" | xargs cat )
		all_def=$(echo "$all_content" | grep -E "^(unsigned[[:space:]]+)?[[:alnum:]]+[[:space:]]+\**[[:alnum:]_]+\([^)]*\)" | tr -d '{' | sed -E 's/\)/\);/')
		main_def=$(echo "${all_def}" | grep -E "^(void|int).+main[(]")
		func_def=$(echo "${all_def}" | grep -v -E "^(void|int).+main[(]")
		output_file="${GENERATED_PATH}/build/${PROJECT_NAME}-${exname}-test-main.o"
		# 소스코드에 메인 함수의 정의가 없다면, 소스 파일 생성
		if [ -z "${main_def}" ]; then
			main_code=$(echo "${include}

${func_def}
${other_code}
int main()
{
	${test_code}
}

")

		# 소스코드에 메인 함수의 정의가 있다면, 소스 파일을 메인용 소스로 이용
		else
			maincode=$(cat "${source_path}/${filename}")
			TAB=$'\t' 
			output_file_regex=$(echo "${output_file}" | sed -E 's/\//\\\//g')
			test_code=$(echo "${test_code}" | sed -E "s/^([[:space:]]*)test/\1${output_file_regex}/g")
		fi

		# cd ${GENERATED_PATH}/src
		printhead "${exname} 테스트를 시작합니다."
		printline
		echo ">>> $exname 테스트용 main 파일 작성 및 컴파일"
		echo "${main_code}" > ${GENERATED_PATH}/src/${PROJECT_NAME}-${exname}-test-main.c
		
		if gcc -Wall -Wextra -Werror -o "${output_file}" \
			${GENERATED_PATH}/src/${PROJECT_NAME}-${exname}-test-main.c \
			${source_path}/*.c ; then
			echo "컴파일이 성공하였습니다."
		else
			echo "컴파일이 실패하였습니다."
			continue
		fi

		echo "완료"


		
		printmsg "테스트 코드"
		echo "${test_code}"
		printmsg "테스트 기댓값 (부정확할 수 있음. 직접 위 코드와 아래 결과 대조 요망)"
		echo "${test_expected}"
		printline
		printmsg "테스트 결과"

		# 만약 main이 없는 함수라면, 테스트 코드를 바로 실행.
		if [ -z "${main_def}" ]; then
			${GENERATED_PATH}/build/${PROJECT_NAME}-${exname}-test-main.o
		# 만약 main이 있는 함수라면, 그냥 실행.
		else
			eval $test_code
		fi
			

		

		
	fi
done
