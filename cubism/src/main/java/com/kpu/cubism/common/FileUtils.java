package com.kpu.cubism.common;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.UUID;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Component;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.multipart.MultipartHttpServletRequest;

import com.kpu.cubism.vo.UploadVo;

@Component("fileUtils")
public class FileUtils {
	// Local Path
	// String path;
	// Server Path
	// String path = "/upload/";
	public List<Map<String, Object>> parseInsertFileInfo(UploadVo uploadVO, HttpServletRequest request) throws Exception{
		
			//Path 설정
			// Set path = request.getSession().getServletContext().getResourcePaths("/");
			// System.out.println("Path : " + path);
			String path = request.getSession().getServletContext().getRealPath("/resources/upload/");
			System.out.println("Path : " + path);
			//MultiparthttpServletRequest 생성
			MultipartHttpServletRequest multi = (MultipartHttpServletRequest)request;
			Iterator<String> iter = multi.getFileNames();
			
			MultipartFile multipartFile = null;
			String originalFileName = "";
			String orginalFileExtension = ""; //암호화된 파일명을 저장하는 변수
			String storedFileName = "";
			String uploadTitle = request.getParameter("uploadTitle");
			String uploadContent = request.getParameter("uploadContent");
			String uploadFlag = request.getParameter("uploadFlag");
			
			List<Map<String, Object>> list = new ArrayList<Map<String, Object>>();
			Map<String, Object> listMap = null;
			//int uploadIdx = uploadVO.getUploadIdx();
			//String uploadFlag = uploadVO.getUploadFlag();
			
			File file = new File(path);
			if(file.exists() == false) {
				file.mkdirs();
			}
			
			while (iter.hasNext()) {
				multipartFile = multi.getFile(iter.next());
				if(multipartFile.isEmpty() == false) {
					originalFileName = multipartFile.getOriginalFilename();
					orginalFileExtension = originalFileName.substring(originalFileName.lastIndexOf("."));
					storedFileName = originalFileName;
					
					//storedFileName = originalFileName + orginalFileExtension;
					//storedFileName = getUuid() + originalFileName;
				}
				file = new File(path + storedFileName);
				multipartFile.transferTo(file);
				
				listMap = new HashMap<String, Object>();
				//listMap.put("uploadIdx", uploadIdx);
				listMap.put("uploadTitle", uploadTitle);
				listMap.put("uploadContent", uploadContent);
				listMap.put("uploadFileName", originalFileName);
				listMap.put("uploadFileRealName", storedFileName);
				listMap.put("uploadFileSize", multipartFile.getSize());
				listMap.put("uploadFlag", uploadFlag);
				list.add(listMap);
			}
			
			return list;
			
	}
	
}
