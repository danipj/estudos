package br.unicamp.ic.mc302.data;

import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Date;

final class DateBR {

	private static String mes[] = new String[] { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho",
			"Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };


	public static String ddmmaa(Date dt) {
		Calendar cal = new GregorianCalendar();
		cal.setTime(dt);

		return cal.get(Calendar.DATE) + "/" + (cal.get(Calendar.MONTH) + 1) + "/"
				+ cal.get(Calendar.YEAR);
	}

	public static String extenso(Date dt) {
		Calendar cal = new GregorianCalendar();
		cal.setTime(dt);
		return cal.get(Calendar.DATE) + " de " + mes[cal.get(Calendar.MONTH)] + " de "
				+ (cal.get(Calendar.YEAR));
	}
}