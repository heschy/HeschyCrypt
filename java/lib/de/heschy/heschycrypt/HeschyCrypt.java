/**
 * 
 */
package de.heschy.heschycrypt;

/**
 * @author henry.schynol
 *
 */
public class HeschyCrypt {
	public static String heschycrypt(boolean mode,String str) {
		String result = new String();
		String passwd = new String("HeschyCryptJava");
		while(passwd.length()<str.length()) {
			passwd.repeat(2);
		}
		char passwdarr[] = passwd.toCharArray();
		if(mode) {
			if(str.length() > 127) {
				int c = 0;
				char a[] = str.toCharArray();
				for(int i = 0; i<str.length();i++) {
					c = (int)a[i];
					c +=i;
					c += (int)passwdarr[i];
					a[i] = (char)c;
				}
				result = String.valueOf(a);
			} else if(str.length() < 127) {
				byte c = 0;
				char a[] = str.toCharArray();
				for(int i = 0; i<str.length();i++) {
					c = (byte)a[i];
					c +=i;
					c += (byte)passwdarr[i];
					a[i] = (char)c;
				}
				result = String.valueOf(a);
			}
			result.replace("\n", "CRYPT:N:CRYPT");
		} else {
			result.replace("\n", "CRYPT:N:CRYPT");
			if(str.length() < 127) {
				byte c = 0;
				char a[] = str.toCharArray();
				for(int i = 0; i<str.length();i++) {
					c = (byte)a[i];
					c -= (byte)passwdarr[i];
					c -=i;
					a[i] = (char)c;
				}
				result = String.valueOf(a);
			} else if(str.length() > 127) {
				int c = 0;
				char a[] = str.toCharArray();
				for(int i = 0; i<str.length();i++) {
					c = (int)a[i];
					c -= (int)passwdarr[i];
					c -=i;
					a[i] = (char)c;
				}
				result = String.valueOf(a);
			}
		}
		
		return result;
	}
	
	public static void main(String[] args) {
		String x = new String("123456789012345");
		System.out.println("1x: " + x);
		x = heschycrypt(true, x);
		System.out.println("2x: " + x);
		x = heschycrypt(false, x);
		System.out.println("3x: " + x);
	}
}
